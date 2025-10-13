#include <unistd.h>
#include <syscall.h>

int link(const char *path1, const char *path2)
{
	return syscall(link, path1, path2);
}
