#include <unistd.h>
#include <syscall.h>

int setegid(gid_t gid)
{
	return syscall(setresgid, -1, gid, -1);
}
