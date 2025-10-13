#include <unistd.h>
#include <syscall.h>

int getresgid(gid_t *restrict rgid, gid_t *restrict egid, gid_t *restrict sgid)
{
	return syscall(getresgid, rgid, egid, sgid);
}
