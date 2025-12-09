


#include <sys/stat.h>  // for chmod
#include <sys/types.h> // for mode_t
#include <syscall.h>   // for __syscall_2, syscall

int chmod(const char *path, mode_t mode)
{
	return syscall(chmod, path, mode);
}
