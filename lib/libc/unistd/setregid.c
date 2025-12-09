#include "asm/unistd_64.h" // for __NR_setregid

#include <syscall.h> // for __syscall_2, syscall
#include <unistd.h>  // for gid_t, setregid

int setregid(gid_t rgid, gid_t egid)
{
	return syscall(setregid, rgid, egid);
}
