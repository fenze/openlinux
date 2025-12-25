#include "linux/io_uring.h" // for io_uring_op
#include "stddef.h"	    // for NULL

#include <__aio.h>  // for __aio_request, aio_request
#include <aio.h>    // for aio_read
#include <stdlib.h> // for malloc

int aio_read(struct aiocb *aiocbp)
{
	struct aio_request *req = malloc(sizeof(*req));

	if (req == NULL)
		return -1;

	req->aiocbp = aiocbp;

	return __aio_request(req, IORING_OP_READ);
}
