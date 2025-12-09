#include "asm/unistd_64.h" // for __NR_geteuid

#include <syscall.h> // for __syscall_0, syscall
#include <unistd.h>  // for geteuid, gid_t

gid_t geteuid(void)
{
	return syscall(geteuid);
}
