#include <fcntl.h>
#include <sys/stat.h>
#include <syscall.h>

int fstat(int fildes, struct stat *buf)
{
	return fstatat(fildes, "", buf, 0);
}
