#include <sys/inotify.h>
#include <syscall.h>

int inotify_init(void)
{
	return syscall(inotify_init);
}
