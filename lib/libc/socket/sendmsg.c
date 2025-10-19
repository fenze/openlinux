#include <syscall.h>
#include <sys/socket.h>

ssize_t sendmsg(int socket, const struct msghdr *message, int flags)
{
	return syscall(sendmsg, socket, message, flags);
}
