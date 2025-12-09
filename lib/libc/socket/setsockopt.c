#include "asm/unistd_64.h" // for __NR_setsockopt

#include <sys/socket.h> // for setsockopt, socklen_t
#include <syscall.h>	// for __syscall_5, syscall

int setsockopt(int socket, int level, int option_name, const void *option_value,
	       socklen_t option_len)
{
	return syscall(setsockopt, socket, level, option_name, option_value,
		       option_len);
}
