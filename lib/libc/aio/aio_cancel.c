#include <__aio.h>
#include <errno.h>
#include <io_uring.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/cdefs.h>

int aio_cancel(int __unused fildes, struct aiocb *aiocbp)
{
	unsigned tail;
	struct aio_request *req;
	struct io_uring_sqe sqe;

	if (aiocbp == NULL) {
		errno = EINVAL;
		return -1;
	}

	req = __aio_lookup(aiocbp);

	if (req == NULL) {
		errno = EINVAL;
		return -1;
	}

	if (req->status == AIO_REQUEST_STATUS_COMPLETED) {
		return AIO_ALLDONE;
	}

	memset(&sqe, 0, sizeof(sqe));
	sqe.opcode = IORING_OP_ASYNC_CANCEL;
	sqe.user_data = (uint64_t)req;

	tail = *__io_uring.sq.tail;
	__io_uring.sq.sqes[tail % IO_URING_ENTRIES] = sqe;
	__io_uring.sq.array[tail % IO_URING_ENTRIES] = tail % IO_URING_ENTRIES;
	*__io_uring.sq.tail = tail + 1;

	io_uring_enter(__io_uring.fd, 1, 0, IORING_ENTER_GETEVENTS, NULL, 0);

	__aio_remove(aiocbp);
	free(req);

	return AIO_CANCELED;
}
