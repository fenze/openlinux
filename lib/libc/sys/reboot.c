#include <linux/reboot.h>
#include <sys/reboot.h>
#include <syscall.h>

int reboot(int op)
{
	return syscall(reboot, LINUX_REBOOT_MAGIC1, LINUX_REBOOT_MAGIC2, op);
}
