#include <unistd.h>
#include <syscall.h>

gid_t geteuid(void)
{
	return syscall(geteuid);
}
