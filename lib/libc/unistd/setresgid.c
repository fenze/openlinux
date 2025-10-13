#include <unistd.h>
#include <syscall.h>

int setresgid(gid_t rgid, gid_t egid, gid_t sgid)
{
	return syscall(setresgid, rgid, egid, sgid);
}
