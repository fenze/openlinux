


#include <sys/socket.h> // for listen
#include <syscall.h>	// for __syscall_2, syscall

int listen(int socket, int backlog)
{
	return syscall(listen, socket, backlog);
}
