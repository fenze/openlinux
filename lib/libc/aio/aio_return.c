#include "aio.h" // for ssize_t, aio_return, aiocb (ptr only)

#include <__aio.h>  // for __aio_remove, aio_request, AIO_REQUEST_STATUS_PE...
#include <errno.h>  // for EINVAL, errno
#include <stddef.h> // for NULL
#include <stdlib.h> // for free

ssize_t aio_return(struct aiocb *aiocbp)
{
	ssize_t result;
	struct aio_request *req;

	if (aiocbp == NULL) {
		errno = EINVAL;
		return -1;
	}

	req = __aio_remove(aiocbp);

	if (req->status == AIO_REQUEST_STATUS_PENDING) {
		free(req);
		return -1;
	}

	result = req->result;
	free(req);
	return result;
}
