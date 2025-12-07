#include <endian.h>
#include <sys/msg.h>
#include <syscall.h>

int msgctl(int msqid, int cmd, struct msqid_ds *buf)
{
	return syscall(msgctl, msqid, cmd, buf);
}
