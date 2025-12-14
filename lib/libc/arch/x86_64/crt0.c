#include <linux/auxvec.h> // for AT_NULL
#include <linux/elf.h>	  // for Elf64_Ehdr
#include "asm/auxvec.h"	  // for AT_SYSINFO_EHDR

#include <stdint.h> // for uintptr_t
#include <stdlib.h> // for exit

#define weak_reference(old, new) \
	extern __typeof(old) new __attribute__((__weak__, __alias__(#old)))

extern int main(int, char *[]);
char **environ;
char *__progname;

struct __attribute__((packed)) auxv_t {
	uintptr_t a_type;
	uintptr_t a_val;
} *__auxv;

static void __vdso_setup(Elf64_Ehdr *vdso_addr __attribute__((unused)))
{
}

weak_reference(__vdso_setup, vdso_setup);

__attribute__((used)) void __libc_start(uintptr_t *sp)
{
	char **argv;
	int argc;

	argc = (int)(*sp);
	argv = (char **)(++sp);
	__progname = argv[0];
	sp += argc;
	environ = (char **)(++sp);

	while (*sp)
		sp++;

	__auxv = (struct auxv_t *)(++sp);
	while (__auxv->a_type != AT_NULL) {
		if (__auxv->a_type == AT_SYSINFO_EHDR) {
			vdso_setup((Elf64_Ehdr *)__auxv->a_val);
		}

		__auxv++;
	}

	exit(main(argc, argv));
}

__attribute__((noreturn, naked)) void _start(void)
{
	__asm__ __volatile__("mov %rsp, %rdi\n"
			     "call __libc_start\n");
}
