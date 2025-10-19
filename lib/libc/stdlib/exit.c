#include <io.h>
#include <libc.h>
#include <unistd.h>
#include <stdio.h>

void (*__dummy_atexit_fvec)(void);
weak_reference(__dummy_atexit_fvec, __atexit_fvec);

void (*__dummy_stdio_cleanup)(void);
weak_reference(__dummy_stdio_cleanup, __stdio_cleanup);

static void __fclose(FILE *fp)
{
	if (fp == NULL) {
		return;
	}

	if (fp->buf_len > 0) {
		fflush(fp);
	}

	if (fp->fd > STDERR_FILENO) {
		close(fp->fd);
	}

	if (fp->buf) {
		free(fp->buf);
	}

	if (fp != stdout && fp != stderr && fp != stdin) {
		free(fp);
	}
}

static void __stdio_cleanup_impl(void)
{
	write(1, "HELLO\n", 6);
	fflush(stdout);

	if (stdout->next != NULL) {
		FILE *cur = stdout->next;
		while (cur) {
			struct __FILE *next = cur->next;
			__fclose(cur);
			cur = next;
		}
	}
}

void exit(int status)
{
	void (*fptr)(void);

	/* Only do stdio cleanup if it was referenced (meaning stdio was used) */
	if (__stdio_cleanup) {
		__stdio_cleanup_impl();
	}

	if (__atexit_fvec) {
		fptr = __atexit_fvec;
		while (fptr) {
			fptr();
			fptr++;
		}
	}

	_exit(status);
}
