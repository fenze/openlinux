#include "asm/unistd_64.h" // for __NR_getgroups

#include <syscall.h> // for __syscall_2, syscall
#include <unistd.h>  // for getgroups, gid_t

int getgroups(int gidsetsize, gid_t grouplist[])
{
	return syscall(getgroups, gidsetsize, grouplist);
}
