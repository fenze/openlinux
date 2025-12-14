

#include <sys/socket.h> // for sendmsg
#include <sys/types.h>	// for ssize_t
#include <syscall.h>	// for __syscall_3, syscall

ssize_t sendmsg(int socket, const struct msghdr *message, int flags)
{
	return syscall(sendmsg, socket, message, flags);
}
