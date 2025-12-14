

#include <sys/stat.h>  // for mkdirat
#include <sys/types.h> // for mode_t
#include <syscall.h>   // for __syscall_3, syscall

int mkdirat(int fd, const char *path, mode_t mode)
{
	return syscall(mkdirat, fd, path, mode);
}
