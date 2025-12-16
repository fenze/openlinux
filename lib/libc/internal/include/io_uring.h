#ifndef __LIBC_IO_URING_H
#define __LIBC_IO_URING_H

#include <linux/io_uring.h>
#include <signal.h>

#define IO_URING_ENTRIES 256

struct io_uring_sq {
	void *ring;
	size_t ring_size;
	struct io_uring_sqe *sqes;

	unsigned *head;
	unsigned *tail;
	unsigned *ring_mask;
	unsigned *ring_entries;
	unsigned *flags;
	unsigned *dropped;
	unsigned *array;
};

struct io_uring_cq {
	void *ring;
	size_t ring_size;

	unsigned *head;
	unsigned *tail;
	unsigned *ring_mask;
	unsigned *ring_entries;
	unsigned *overflow;
	struct io_uring_cqe *cqes;
	unsigned *flags;
};

struct io_uring {
	int fd;
	int eventfd;

	struct io_uring_sq sq;
	struct io_uring_cq cq;
};

extern struct io_uring __io_uring;

int io_uring_setup(unsigned int, struct io_uring_params *);

int io_uring_register(unsigned int, unsigned int, void *, unsigned int);

int io_uring_enter(unsigned int, unsigned int, unsigned int, unsigned int,
		   sigset_t *, size_t);

#endif
