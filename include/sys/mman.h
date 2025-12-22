#ifndef __SYS_MMAN_H
#define __SYS_MMAN_H

#include <stddef.h>
typedef __SIZE_TYPE__ size_t;
typedef __INT64_TYPE__ off_t;
typedef __UINT32_TYPE__ mode_t;

#define PROT_NONE  0
#define PROT_READ  1
#define PROT_WRITE 2
#define PROT_EXEC  4

#define MAP_FAILED ((void *)-1)

#define MAP_FIXED     0x10
#define MAP_ANON      0x20
#define MAP_ANONYMOUS MAP_ANON
#define MAP_PRIVATE   0x02
#define MAP_SHARED    0x01

#define MAP_NORESERVE 0x04000
#define MAP_POPULATE  0x08000

#define POSIX_MADV_NORMAL     0
#define POSIX_MADV_RANDOM     1
#define POSIX_MADV_SEQUENTIAL 2
#define POSIX_MADV_WILLNEED   3
#define POSIX_MADV_DONTNEED   4

void *mmap(void *, size_t, int, int, int, off_t);
int munmap(void *, size_t);
int posix_madvise(void *, size_t, int);
int mprotect(void *, size_t, int);

#endif
