#include <sys/stat.h>
#include <syscall.h>

mode_t umask(mode_t cmask)
{
	return syscall(umask, cmask);
}
