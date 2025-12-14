

#include <fcntl.h>     // for creat
#include <sys/types.h> // for mode_t
#include <syscall.h>   // for __syscall_2, syscall

int creat(const char *path, mode_t mode)
{
	return syscall(creat, path, mode);
}
