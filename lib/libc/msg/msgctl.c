

#include <sys/msg.h> // for msgctl
#include <syscall.h> // for __syscall_3, syscall

int msgctl(int msqid, int cmd, struct msqid_ds *buf)
{
	return syscall(msgctl, msqid, cmd, buf);
}
