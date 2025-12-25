#include "aio.h"	    // for AIO_ALLDONE, AIO_CANCELED, aio_cancel
#include "linux/io_uring.h" // for io_uring_sqe, IORING_ENTER_GETEVENTS

#include <__aio.h>     // for __aio_lookup, __aio_remove, AIO_REQUEST_...
#include <errno.h>     // for EINVAL, errno
#include <io_uring.h>  // for __io_uring, io_uring, io_uring_sq, IO_UR...
#include <stddef.h>    // for NULL
#include <stdint.h>    // for uint64_t
#include <stdlib.h>    // for free
#include <string.h>    // for memset
#include <sys/cdefs.h> // for __unused

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
