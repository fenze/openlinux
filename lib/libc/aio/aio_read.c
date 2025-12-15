#include <__aio.h>
#include <aio.h>
#include <io_uring.h>
#include <stdlib.h>

int aio_read(struct aiocb *aiocbp)
{
	struct aio_request *req = malloc(sizeof(*req));

	if (req == NULL)
		return -1;

	req->aiocbp = aiocbp;

	return __aio_request(req, IORING_OP_READ);
}
