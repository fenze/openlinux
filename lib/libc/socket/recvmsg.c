


#include <sys/socket.h> // for recvmsg
#include <sys/types.h>	// for ssize_t
#include <syscall.h>	// for __syscall_3, syscall

ssize_t recvmsg(int socket, struct msghdr *message, int flags)
{
	return syscall(recvmsg, socket, message, flags);
}
