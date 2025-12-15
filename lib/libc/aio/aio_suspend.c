#include <__aio.h>
#include <aio.h>
#include <errno.h>
#include <io_uring.h>
#include <poll.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

int aio_suspend(const struct aiocb *const list[], int nent,
		const struct timespec *timeout)
{
	struct pollfd pfd;
	struct aio_request *req;

	if ((void *)list == NULL || nent <= 0) {
		errno = EINVAL;
		return -1;
	}

	while (1) {
		int timeout_ms, ret;
		__aio_poll();

		for (int i = 0; i < nent; i++) {
			req = __aio_lookup((struct aiocb *)list[i]);
			if (req && req->status == AIO_REQUEST_STATUS_COMPLETED)
				return 0;
		}

		pfd.fd = __io_uring.eventfd;
		pfd.events = POLLIN;

		if (timeout) {
			timeout_ms = timeout->tv_sec * 1000 +
				     timeout->tv_nsec / 1000000;
		} else {
			timeout_ms = -1;
		}

		ret = poll(&pfd, 1, timeout_ms);

		if (ret == 0) {
			errno = EAGAIN;
			return -1;
		}

		if (ret < 0) {
			return -1;
		}

		uint64_t val;
		read(__io_uring.eventfd, &val, sizeof(val));
		io_uring_enter(__io_uring.fd, 0, 0, IORING_ENTER_GETEVENTS,
			       NULL, 0);
	}
}
