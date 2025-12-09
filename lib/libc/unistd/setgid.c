#include "asm/unistd_64.h" // for __NR_setgid

#include <syscall.h> // for __syscall_1, syscall
#include <unistd.h>  // for gid_t, setgid

int setgid(gid_t gid)
{
	return syscall(setgid, gid);
}
