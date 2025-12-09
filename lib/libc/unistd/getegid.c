#include "asm/unistd_64.h" // for __NR_getegid

#include <syscall.h> // for __syscall_0, syscall
#include <unistd.h>  // for getegid, gid_t

gid_t getegid(void)
{
	return syscall(getegid);
}
