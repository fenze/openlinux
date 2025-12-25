#include "aio.h" // for aio_error, aiocb (ptr only)

#include <__aio.h>  // for aio_request, __aio_lookup, AIO_REQUEST_STATUS_PE...
#include <errno.h>  // for EINVAL, errno, EINPROGRESS
#include <stddef.h> // for NULL

int aio_error(const struct aiocb *aiocbp)
{
	struct aio_request *req;

	if (aiocbp == NULL) {
		errno = EINVAL;
		return -1;
	}

	req = __aio_lookup(aiocbp);

	if (req == NULL) {
		errno = EINVAL;
		return -1;
	}

	if (req->status == AIO_REQUEST_STATUS_PENDING) {
		return EINPROGRESS;
	}

	return req->result < 0 ? -req->result : 0;
}
