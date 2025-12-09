#include "asm/unistd_64.h" // for __NR_getgid

#include <syscall.h> // for __syscall_0, syscall
#include <unistd.h>  // for getgid, gid_t

gid_t getgid(void)
{
	return syscall(getgid);
}
