

#include <syscall.h> // for __syscall_2, syscall
#include <unistd.h>  // for uid_t, setreuid

int setreuid(uid_t ruid, uid_t euid)
{
	return syscall(setreuid, ruid, euid);
}
