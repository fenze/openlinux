#include <unistd.h>
#include <syscall.h>

int setregid(gid_t rgid, gid_t egid)
{
	return syscall(setregid, rgid, egid);
}
