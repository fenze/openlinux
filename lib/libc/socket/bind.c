#include "asm/unistd_64.h" // for __NR_bind

#include <sys/socket.h> // for bind, socklen_t
#include <syscall.h>	// for __syscall_3, syscall

int bind(int socket, const struct sockaddr *address, socklen_t address_len)
{
	return syscall(bind, socket, address, address_len);
}
