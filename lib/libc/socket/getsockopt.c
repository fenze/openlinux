

#include <sys/socket.h> // for getsockopt, socklen_t
#include <syscall.h>	// for __syscall_5, syscall

int getsockopt(int socket, int level, int option_name, void *restrict option_value, socklen_t *restrict option_len)
{
	return syscall(getsockopt, socket, level, option_name, option_value, option_len);
}
