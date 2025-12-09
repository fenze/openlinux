#include "asm/unistd_64.h" // for __NR_lseek

#include <syscall.h> // for __syscall_3, syscall
#include <unistd.h>  // for off_t, lseek

off_t lseek(int fildes, off_t offset, int whence)
{
	return syscall(lseek, fildes, offset, whence);
}
