#include <unistd.h>
#include <syscall.h>

int setgid(gid_t gid)
{
	return syscall(setgid, gid);
}
