#include <libc.h>   // for weak_reference
#include <stdlib.h> // for free, exit
#include <unistd.h> // for _exit, close, write, STDERR_FILENO

void (*__dummy_atexit_fvec)(void);
weak_reference(__dummy_atexit_fvec, __atexit_fvec);

void exit(int status)
{
	void (*fptr)(void);

	if (__atexit_fvec) {
		fptr = __atexit_fvec;
		while (fptr) {
			fptr();
			fptr++;
		}
	}

	_exit(status);
}
