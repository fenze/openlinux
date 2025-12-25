#include "linux/io_uring.h" // for io_uring_op, IORING_FSYNC_DATASYNC
#include "stddef.h"	    // for NULL

#include <__aio.h> // for __aio_lookup, __aio_request
#include <aio.h>   // for aio_fsync
#include <errno.h> // for EINVAL, errno
#include <fcntl.h> // for O_DSYNC

int aio_fsync(int op, struct aiocb *aiocbp)
{
	int opcode;
	struct aio_request *req;

	req = __aio_lookup(aiocbp);

	if (req == NULL) {
		errno = EINVAL;
		return -1;
	}

	if (op == O_DSYNC) {
		opcode = IORING_OP_FSYNC | IORING_FSYNC_DATASYNC;
	} else {
		opcode = IORING_OP_FSYNC;
	}

	return __aio_request(req, opcode);
}
