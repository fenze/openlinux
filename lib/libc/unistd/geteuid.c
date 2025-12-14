

#include <syscall.h> // for __syscall_0, syscall
#include <unistd.h>  // for geteuid, gid_t

gid_t geteuid(void)
{
	return syscall(geteuid);
}
