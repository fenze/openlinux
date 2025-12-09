


#include <asm-generic/sockios.h> // for SIOCATMARK
#include <syscall.h>		 // for __syscall_3, syscall

int sockatmark(int s)
{
	int arg = 0;
	return syscall(ioctl, s, SIOCATMARK, &arg) < 0 ? -1 : arg;
}
