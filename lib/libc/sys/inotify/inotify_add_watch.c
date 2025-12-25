#include <stdint.h>
#include <sys/inotify.h>
#include <syscall.h>

int inotify_add_watch(int fildes, const char *name, uint32_t mask)
{
	return syscall(inotify_add_watch, fildes, name, mask);
}
