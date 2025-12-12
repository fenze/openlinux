#include <sys/mount.h> // for mount
#include <syscall.h>   // for __syscall_5, syscall

int mount(const char *source, const char *target, const char *filesystemtype,
	  unsigned long mountflags, const void *_Nullable data)
{
	return syscall(mount, source, target, filesystemtype, mountflags, data);
}
