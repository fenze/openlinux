#include <alloca.h>
#include <libc.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/cdefs.h>

#define BUFSIZ 4096

extern void __libc_init_vdso(void) __attribute__((weak));
extern void __libc_init_tls(void) __attribute__((weak));
extern void __libc_init_io(void) __attribute__((weak));

extern int main(int, char **, char **);

struct libc __libc = { 0 };
char **environ;
char *__progname;

__used void __libc_init(uintptr_t *rsp)
{
	char **argv;
	int argc;

	argc = (int)(*rsp);
	argv = (char **)(++rsp);

	rsp += argc;

	environ = (char **)(++rsp);
	__progname = argv[0];

	while (*rsp)
		rsp++;

	__libc.auxv = (size_t *)++rsp;

	if (__libc_init_io) {
		__libc_init_io();

		__libc.stdout.buf = alloca(BUFSIZ);
		__libc.stdout.buf_size = BUFSIZ;
		__libc.stdout.buf_len = 0;
		__libc.stdout.buf_pos = 0;

		__libc.stdin.buf = alloca(BUFSIZ);
		__libc.stdin.buf_size = BUFSIZ;
		__libc.stdin.buf_len = 0;
		__libc.stdin.buf_pos = 0;
	}

	if (__libc_init_tls)
		__libc_init_tls();

	if (__libc_init_vdso)
		__libc_init_vdso();

	exit(main(argc, argv, environ));
}
