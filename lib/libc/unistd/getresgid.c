


#include <syscall.h> // for __syscall_3, syscall
#include <unistd.h>  // for gid_t, getresgid

int getresgid(gid_t *restrict rgid, gid_t *restrict egid, gid_t *restrict sgid)
{
	return syscall(getresgid, rgid, egid, sgid);
}
