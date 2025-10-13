#include <unistd.h>
#include <syscall.h>

int getresuid(uid_t *restrict ruid, uid_t *restrict euid, uid_t *restrict suid)
{
	return syscall(getresuid, ruid, euid, suid);
}
