#include "asm/unistd_64.h" // for __NR_setsid

#include <syscall.h> // for __syscall_0, syscall
#include <unistd.h>  // for pid_t, setsid

pid_t setsid(void)
{
	return syscall(setsid);
}
