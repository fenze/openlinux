#include "asm/unistd_64.h" // for __NR_utimensat

#include <syscall.h> // for __syscall_4, syscall
#include <time.h>    // for timespec

int utimensat(int fd, const char *path, const struct timespec times[2],
	      int flag)
{
	return syscall(utimensat, fd, path, times, flag);
}
