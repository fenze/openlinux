


#include <sys/stat.h>  // for fchmod
#include <sys/types.h> // for mode_t
#include <syscall.h>   // for __syscall_2, syscall

int fchmod(int fildes, mode_t mode)
{
	return syscall(fchmod, fildes, mode);
}
