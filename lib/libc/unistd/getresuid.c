#include "asm/unistd_64.h" // for __NR_getresuid

#include <syscall.h> // for __syscall_3, syscall
#include <unistd.h>  // for uid_t, getresuid

int getresuid(uid_t *restrict ruid, uid_t *restrict euid, uid_t *restrict suid)
{
	return syscall(getresuid, ruid, euid, suid);
}
