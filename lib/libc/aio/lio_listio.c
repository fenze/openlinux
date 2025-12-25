#include <__aio.h>	 // for lio_group, __aio_lookup, aio_request
#include <aio.h>	 // for LIO_NOWAIT, aio_read, aio_write, LIO_NOP
#include <errno.h>	 // for errno, EINVAL, EIO
#include <stddef.h>	 // for NULL
#include <stdint.h>	 // for uint64_t
#include <stdlib.h>	 // for malloc
#include <string.h>	 // for memset
#include <sys/eventfd.h> // for eventfd, EFD_CLOEXEC
#include <unistd.h>	 // for read

int lio_listio(int mode, struct aiocb *restrict const list[restrict], int nent, struct sigevent *restrict sig)
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
