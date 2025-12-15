#include <syscall.h>
#include <unistd.h>

int chroot(const char *path)
{
	return syscall(chroot, path);
}
