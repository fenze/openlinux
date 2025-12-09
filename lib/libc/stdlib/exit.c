#include "__stdio.h" // for __FILE
#include "stddef.h"  // for NULL

#include <libc.h>   // for weak_reference
#include <stdio.h>  // for fflush, stdout, FILE, stderr, stdin
#include <stdlib.h> // for free, exit
#include <unistd.h> // for _exit, close, write, STDERR_FILENO

void (*__dummy_atexit_fvec)(void);
weak_reference(__dummy_atexit_fvec, __atexit_fvec);

void (*__dummy_stdio_cleanup)(void);
weak_reference(__dummy_stdio_cleanup, __stdio_cleanup);

static void __fclose(FILE *stream)
{
	if (stream == NULL) {
		return;
	}

	if (__FILE(stream)->buf_len > 0) {
		fflush(stream);
	}

	if (__FILE(stream)->fd > STDERR_FILENO) {
		close(__FILE(stream)->fd);
	}

	if (__FILE(stream)->buf) {
		free(__FILE(stream)->buf);
	}

	if (stream != stdout && stream != stderr && stream != stdin) {
		free(stream);
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

	/* Only do stdio cleanup if it was referenced (meaning stdio was used)
	 */
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
