


#include <syscall.h> // for __syscall_3, syscall
#include <unistd.h>  // for gid_t, setegid

int setegid(gid_t gid)
{
	return syscall(setresgid, -1, gid, -1);
}
