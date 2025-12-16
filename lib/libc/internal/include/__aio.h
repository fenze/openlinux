#ifndef __LIBC_AIO_H
#define __LIBC_AIO_H

#include <aio.h>

#define AIO_REQUEST_STATUS_PENDING   0
#define AIO_REQUEST_STATUS_COMPLETED 1

struct lio_group {
	int pending;
	int error;
	int eventfd;
	struct sigevent *sig;
};

struct aio_context {
	struct aio_request *head;
	struct aio_request *tail;
};

struct aio_request {
	struct aiocb *aiocbp;
	int status;
	ssize_t result;
	struct aio_request *next;
	struct lio_group *grp;
};

void __aio_poll(void);

int __aio_request(struct aio_request *, int);
struct aio_request *__aio_lookup(const struct aiocb *);
struct aio_request *__aio_remove(const struct aiocb *);

#endif
