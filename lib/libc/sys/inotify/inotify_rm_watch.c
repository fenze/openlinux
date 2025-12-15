#include <sys/inotify.h>
#include <syscall.h>

int inotify_rm_watch(int fildes, int wd)
{
	return syscall(inotify_rm_watch, fildes, wd);
}
