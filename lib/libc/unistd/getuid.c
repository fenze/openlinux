#include "asm/unistd_64.h" // for __NR_getuid

#include <syscall.h> // for __syscall_0, syscall
#include <unistd.h>  // for getuid, uid_t

uid_t getuid(void)
{
	return syscall(getuid);
}
