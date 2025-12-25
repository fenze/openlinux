#ifndef __BITS_SELECT_H
#define __BITS_SELECT_H

#ifndef __BITS_SELECT_H_
#error "Internal header — include the public API header instead."
#else
#undef __BITS_SELECT_H_
#endif

#define FD_SETSIZE 1024

#define FD_ZERO(set) __builtin_memset((set), 0, sizeof(*(set)))

#define FD_SET(fd, set) \
	((set)->fds_bits[(fd) / (8 * sizeof(unsigned long))] |= 1UL << ((fd) % (8 * sizeof(unsigned long))))

#define FD_CLR(fd, set) \
	((set)->fds_bits[(fd) / (8 * sizeof(unsigned long))] &= ~(1UL << ((fd) % (8 * sizeof(unsigned long)))))

#define FD_ISSET(fd, set) \
	((set)->fds_bits[(fd) / (8 * sizeof(unsigned long))] & (1UL << ((fd) % (8 * sizeof(unsigned long)))))

typedef __INT64_TYPE__ time_t;
typedef __INT64_TYPE__ suseconds_t;

typedef struct {
	unsigned long fds_bits[1024 / (8 * sizeof(unsigned long))];
} fd_set;

struct timeval {
	time_t tv_sec;
	suseconds_t tv_usec;
};

#endif
