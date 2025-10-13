#include <unistd.h>
#include <syscall.h>

int seteuid(uid_t uid)
{
	return syscall(setresuid, -1, uid, -1);
}
