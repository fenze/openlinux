#include <unistd.h>
#include <syscall.h>

int setuid(uid_t uid)
{
	return syscall(setuid, uid);
}
