#include "asm/unistd_64.h" // for __NR_setresuid

#include <syscall.h> // for __syscall_3, syscall
#include <unistd.h>  // for uid_t, setresuid

int setresuid(uid_t ruid, uid_t euid, uid_t suid)
{
	return syscall(setresuid, ruid, euid, suid);
}
