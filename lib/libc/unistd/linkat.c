#include <unistd.h>
#include <syscall.h>

int linkat(int fd1, const char *path1, int fd2, const char *path2, int flag)
{
	return syscall(linkat, fd1, path1, fd2, path2, flag);
}
