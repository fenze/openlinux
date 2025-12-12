#include <sys/sysinfo.h>
#include <syscall.h>

int sysinfo(struct sysinfo *info)
{
	return syscall(sysinfo, info);
}
