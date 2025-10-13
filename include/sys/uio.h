#ifndef __SYS_UIO_H
#define __SYS_UIO_H

typedef __SIZE_TYPE__ size_t;
typedef __INT64_TYPE__ ssize_t;

struct iovec {
	void *iov_base;
	size_t iov_len;
};

ssize_t readv(int, const struct iovec *, int);
ssize_t writev(int, const struct iovec *, int);

#endif
