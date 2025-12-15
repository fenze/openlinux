#include <__aio.h>
#include <io_uring.h>
#include <signal.h>
#include <stdint.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

struct aio_context __aio_context = { 0 };

// TODO
// static void *__aio_thread_notify(void *arg)
// {
// 	struct sigevent *sev = arg;
// 	sev->sigev_notify_function(sev->sigev_value);
// 	return NULL;
// }

static void __aio_deliver_signal(struct sigevent *sev)
{
	if (!sev)
		return;

	switch (sev->sigev_notify) {
	case SIGEV_SIGNAL:
		kill(getpid(), sev->sigev_signo);
		break;

	case SIGEV_THREAD: {
		// TODO
		// pthread_t thread;
		// pthread_create(&thread, NULL, __aio_thread_notify, sev);
		// pthread_detach(thread);
		break;
	}

	default:
		break;
	}
}

static void __aio_complete(struct aio_request *req, int res)
{
	req->result = res;
	req->status = AIO_REQUEST_STATUS_COMPLETED;

	if (req->grp) {
		if (res < 0)
			req->grp->error = 1;

		if (--req->grp->pending == 0) {
			uint64_t one = 1;
			write(req->grp->eventfd, &one, sizeof(one));

			if (req->grp->sig) {
				__aio_deliver_signal(req->grp->sig);
			}
		}
	}
}

int __aio_request(struct aio_request *req, int opcode)
{
	struct io_uring_sqe *sqe;
	unsigned index, tail;

	if (req == NULL)
		return -1;

	tail = *__io_uring.sq.tail;
	index = tail & *__io_uring.sq.ring_mask;

	sqe = &__io_uring.sq.sqes[index];
	memset(sqe, 0, sizeof(*sqe));
	sqe->opcode = opcode;
	sqe->fd = req->aiocbp->aio_fildes;
	sqe->addr = (uint64_t)req->aiocbp->aio_buf;
	sqe->len = req->aiocbp->aio_nbytes;
	sqe->off = req->aiocbp->aio_offset;
	sqe->user_data = (uint64_t)req;

	__io_uring.sq.array[index] = index;
	*__io_uring.sq.tail = tail + 1;

	io_uring_enter(__io_uring.fd, 1, 0, IORING_ENTER_GETEVENTS, NULL, 0);

	req->status = AIO_REQUEST_STATUS_PENDING;
	req->next = NULL;

	if (__aio_context.head == NULL) {
		__aio_context.head = __aio_context.tail = req;
	} else {
		__aio_context.tail->next = req;
		__aio_context.tail = req;
	}

	return 0;
}

void __aio_poll(void)
{
	unsigned head = *__io_uring.cq.head;
	unsigned tail = *__io_uring.cq.tail;

	while (head != tail) {
		struct io_uring_cqe *cqe =
			&__io_uring.cq.cqes[head & *__io_uring.cq.ring_mask];

		struct aio_request *req = (struct aio_request *)cqe->user_data;

		__aio_complete(req, cqe->res);

		head++;
	}

	*__io_uring.cq.head = head;
}

struct aio_request *__aio_lookup(const struct aiocb *aiocbp)
{
	struct aio_request *req = __aio_context.head;

	while (req != NULL) {
		if (req->aiocbp == aiocbp)
			return req;

		req = req->next;
	}

	return NULL;
}

struct aio_request *__aio_remove(const struct aiocb *aiocbp)
{
	struct aio_request **cur = &__aio_context.head;
	struct aio_request *req = NULL;

	while (*cur) {
		if ((*cur)->aiocbp == aiocbp) {
			req = *cur;
			*cur = req->next;
			if (__aio_context.tail == req)
				__aio_context.tail = NULL;
			break;
		}
		cur = &(*cur)->next;
	}

	return req;
}
