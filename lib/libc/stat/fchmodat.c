

#include <sys/stat.h>  // for fchmodat
#include <sys/types.h> // for mode_t
#include <syscall.h>   // for __syscall_4, syscall

int fchmodat(int fd, const char *path, mode_t mode, int flag)
{
	return syscall(fchmodat2, fd, path, mode, flag);
}
