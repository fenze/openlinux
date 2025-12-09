#include "asm/unistd_64.h" // for __NR_mknodat

#include <fcntl.h>     // for AT_FDCWD
#include <sys/stat.h>  // for mknod
#include <sys/types.h> // for dev_t, mode_t
#include <syscall.h>   // for __syscall_4, syscall

int mknod(const char *path, mode_t mode, dev_t dev)
{
	return syscall(mknodat, AT_FDCWD, path, mode, dev);
}
