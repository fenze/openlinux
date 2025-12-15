#ifndef __SYS_EVENTFD_H
#define __SYS_EVENTFD_H

#include <sys/cdefs.h>

__BEGIN_DECLS

typedef __UINT64_TYPE__ eventfd_t;

#define EFD_SEMAPHORE (1 << 0)
#define EFD_CLOEXEC   02000000
#define EFD_NONBLOCK  00004000

int eventfd(unsigned int, int);
int eventfd_read(int, eventfd_t *);
int eventfd_write(int, eventfd_t);

__END_DECLS

#endif
