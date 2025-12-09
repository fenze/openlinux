#include "asm/unistd_64.h" // for __NR_listen

#include <sys/socket.h> // for listen
#include <syscall.h>	// for __syscall_2, syscall

int listen(int socket, int backlog)
{
	return syscall(listen, socket, backlog);
}
