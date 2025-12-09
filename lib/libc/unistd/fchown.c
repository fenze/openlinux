#include "asm/unistd_64.h" // for __NR_fchown

#include <syscall.h> // for __syscall_3, syscall
#include <unistd.h>  // for fchown, gid_t, uid_t

int fchown(int fildes, uid_t owner, gid_t group)
{
	return syscall(fchown, fildes, owner, group);
}
