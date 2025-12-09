


#include <syscall.h> // for __syscall_3, syscall
#include <unistd.h>  // for gid_t, setresgid

int setresgid(gid_t rgid, gid_t egid, gid_t sgid)
{
	return syscall(setresgid, rgid, egid, sgid);
}
