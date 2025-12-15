#include <__aio.h>
#include <aio.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/eventfd.h>
#include <unistd.h>
#include <stdint.h>

int lio_listio(int mode, struct aiocb *restrict const list[restrict], int nent,
	       struct sigevent *restrict sig)
{
	struct lio_group *grp = NULL;

	if ((void *)list == NULL || nent <= 0) {
		errno = EINVAL;
		return -1;
	}

	if (mode != LIO_WAIT && mode != LIO_NOWAIT) {
		errno = EINVAL;
		return -1;
	}

	grp = malloc(sizeof(*grp));
	memset(grp, 0, sizeof(*grp));

	grp->eventfd = eventfd(0, EFD_CLOEXEC);
	grp->sig = sig;

	for (int i = 0; i < nent; i++) {
		int ret;
		struct aio_request *req;
		struct aiocb *aiocbp = list[i];

		if (aiocbp == NULL) {
			continue;
		}

		switch (aiocbp->aio_lio_opcode) {
		case LIO_READ:
			ret = aio_read(aiocbp);
			break;
		case LIO_WRITE:
			ret = aio_write(aiocbp);
			break;
		case LIO_NOP:
			ret = 0;
			continue;
		default:
			errno = EINVAL;
			return -1;
		}

		if (ret < 0) {
			return -1;
		}

		req = __aio_lookup(aiocbp);
		req->grp = grp;
		grp->pending++;
	}

	if (mode == LIO_NOWAIT) {
		return 0;
	}

	while (grp->pending > 0) {
		uint64_t val;
		if (read(grp->eventfd, &val, sizeof(val)) < 0) {
			return -1;
		}
	}

	if (grp->error) {
		errno = EIO;
		return -1;
	}

	return 0;
}
