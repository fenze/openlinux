#include <__aio.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

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
