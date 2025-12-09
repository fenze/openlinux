#include "asm/unistd_64.h" // for __NR_mkdir

#include <sys/stat.h>  // for mkdir
#include <sys/types.h> // for mode_t
#include <syscall.h>   // for __syscall_2, syscall

int mkdir(const char *path, mode_t mode)
{
#ifdef __NR_mkdir
	return syscall(mkdir, path, mode);
#else
	return syscall(mkdirat, AT_FDCWD, path, mode);
#endif
}
