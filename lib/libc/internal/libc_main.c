#include <libc.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/cdefs.h>

extern void __init_vdso(void);

struct libc __libc;
char **environ;
char *__progname;

extern int main(int, char **, char **);

__used void __libc_main(uintptr_t *rsp)
{
	char **argv;
	size_t *auxv;
	int argc;

	argc = (int)(*rsp);
	argv = (char **)(++rsp);

	rsp += argc;

	environ = (char **)(++rsp);
	__progname = argv[0];

	while (*rsp)
		rsp++;

	auxv = (size_t *)++rsp;

	for (size_t i = 0; auxv[i]; i += 2)
		__libc.auxv[auxv[i]] = auxv[i + 1];

	__init_vdso();

	exit(main(argc, argv, environ));
}
