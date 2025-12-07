#include <unistd.h>
#include <syscall.h>

int getgroups(int gidsetsize, gid_t grouplist[])
{
	return syscall(getgroups, gidsetsize, grouplist);
}
