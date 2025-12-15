#include <libc.h>
#include <sys/cdefs.h>

__dead __naked void _start(void)
{
	__asm__ __volatile__("mov %rsp, %rdi\n"
			     "call __libc_main\n");
}
