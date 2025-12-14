

#include <sys/stat.h>  // for mknodat
#include <sys/types.h> // for dev_t, mode_t
#include <syscall.h>   // for __syscall_4, syscall

int mknodat(int fd, const char *path, mode_t mode, dev_t dev)
{
	return syscall(mknodat, fd, path, mode, dev);
}
