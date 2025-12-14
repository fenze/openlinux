

#include <syscall.h> // for __syscall_2, syscall
#include <unistd.h>  // for link

int link(const char *path1, const char *path2)
{
	return syscall(link, path1, path2);
}
