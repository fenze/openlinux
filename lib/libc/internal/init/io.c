#include "__stdio.h"
#include "stddef.h"
#include <fcntl.h>
#include <libc.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct __FILE *const stdout = (struct __FILE *)&__libc.stdout;
struct __FILE *const stdin = (struct __FILE *)&__libc.stdin;
struct __FILE *const stderr = (struct __FILE *)&__libc.stderr;

void __libc_init_io(void)
{
	/* stdout */
	memset(&__libc.stdout, 0, sizeof(struct __FILE));
	__libc.stdout.fd = STDOUT_FILENO;
	__libc.stdout.flags = O_WRONLY;
	__libc.stdout.type = _IOLBF;
	__libc.stdout.buf = NULL;
	__libc.stdout.buf_size = 0;
	__libc.stdout.buf_len = 0;
	__libc.stdout.buf_pos = 0;

	/* stdin */
	memset(&__libc.stdin, 0, sizeof(struct __FILE));
	__libc.stdin.fd = STDIN_FILENO;
	__libc.stdin.flags = O_RDONLY;
	__libc.stdin.type = _IONBF;
	__libc.stdin.buf = NULL;
	__libc.stdin.buf_size = 0;
	__libc.stdin.buf_len = 0;
	__libc.stdin.buf_pos = 0;

	/* stderr */
	memset(&__libc.stderr, 0, sizeof(struct __FILE));
	__libc.stderr.fd = STDERR_FILENO;
	__libc.stderr.flags = O_WRONLY;
	__libc.stderr.type = _IONBF;
	__libc.stderr.buf = NULL;
	__libc.stderr.buf_size = 0;
	__libc.stderr.buf_len = 0;
	__libc.stderr.buf_pos = 0;
}
