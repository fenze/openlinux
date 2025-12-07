#include <unistd.h>
#include <syscall.h>

int setreuid(uid_t ruid, uid_t euid)
{
	return syscall(setreuid, ruid, euid);
}
