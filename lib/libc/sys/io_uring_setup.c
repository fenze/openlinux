#include <sys/eventfd.h>
#include <io_uring.h>
#include <string.h>
#include <sys/mman.h>
#include <syscall.h>

struct io_uring __io_uring;

int io_uring_setup(unsigned int entries, struct io_uring_params *params)
{
	return syscall(io_uring_setup, entries, params);
}

int __io_uring_setup(void)
{
	struct io_uring_params p;
	memset(&p, 0, sizeof(p));

	__io_uring.fd = io_uring_setup(IO_URING_ENTRIES, &p);

	if (__io_uring.fd < 0)
		return -1;

	__io_uring.sq.ring_size =
		p.sq_off.array + p.sq_entries * sizeof(unsigned int);
	__io_uring.sq.ring = mmap(NULL, __io_uring.sq.ring_size,
				  PROT_READ | PROT_WRITE,
				  MAP_SHARED | MAP_POPULATE, __io_uring.fd,
				  IORING_OFF_SQ_RING);

	if (__io_uring.sq.ring == MAP_FAILED)
		return -1;

	__io_uring.sq.head = __io_uring.sq.ring + p.sq_off.head;
	__io_uring.sq.tail = __io_uring.sq.ring + p.sq_off.tail;
	__io_uring.sq.ring_mask = __io_uring.sq.ring + p.sq_off.ring_mask;
	__io_uring.sq.ring_entries = __io_uring.sq.ring + p.sq_off.ring_entries;
	__io_uring.sq.flags = __io_uring.sq.ring + p.sq_off.flags;
	__io_uring.sq.dropped = __io_uring.sq.ring + p.sq_off.dropped;
	__io_uring.sq.array = __io_uring.sq.ring + p.sq_off.array;
	__io_uring.sq.sqes =
		mmap(NULL, p.sq_entries * sizeof(struct io_uring_sqe),
		     PROT_READ | PROT_WRITE, MAP_SHARED | MAP_POPULATE,
		     __io_uring.fd, IORING_OFF_SQES);

	if (__io_uring.sq.sqes == MAP_FAILED) {
		munmap(__io_uring.sq.ring, __io_uring.sq.ring_size);
		return -1;
	}

	__io_uring.cq.ring_size =
		p.cq_off.cqes + p.cq_entries * sizeof(struct io_uring_cqe);
	__io_uring.cq.ring = mmap(NULL, __io_uring.cq.ring_size,
				  PROT_READ | PROT_WRITE,
				  MAP_SHARED | MAP_POPULATE, __io_uring.fd,
				  IORING_OFF_CQ_RING);

	if (__io_uring.cq.ring == MAP_FAILED) {
		munmap(__io_uring.sq.ring, __io_uring.sq.ring_size);
		munmap(__io_uring.sq.sqes,
		       p.sq_entries * sizeof(struct io_uring_sqe));
		return -1;
	}

	__io_uring.eventfd = eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
	if (__io_uring.eventfd < 0)
		return -1;

	io_uring_register(__io_uring.fd, IORING_REGISTER_EVENTFD,
			  &__io_uring.eventfd, 1);

	__io_uring.cq.head = __io_uring.cq.ring + p.cq_off.head;
	__io_uring.cq.tail = __io_uring.cq.ring + p.cq_off.tail;
	__io_uring.cq.ring_mask = __io_uring.cq.ring + p.cq_off.ring_mask;
	__io_uring.cq.ring_entries = __io_uring.cq.ring + p.cq_off.ring_entries;
	__io_uring.cq.overflow = __io_uring.cq.ring + p.cq_off.overflow;
	__io_uring.cq.cqes = __io_uring.cq.ring + p.cq_off.cqes;
	__io_uring.cq.flags = __io_uring.cq.ring + p.cq_off.flags;

	return 0;
}
