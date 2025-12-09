


#include <syscall.h> // for __syscall_2, syscall
#include <unistd.h>  // for pid_t, setpgid

int setpgid(pid_t pid, pid_t pgid)
{
	return syscall(setpgid, pid, pgid);
}
