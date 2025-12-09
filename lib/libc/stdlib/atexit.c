#include "stddef.h" // for NULL

#include <stdlib.h> // for atexit

static void (*__atexit_fvec[32])(void) = { NULL };

int atexit(void (*func)(void))
{
	for (int i = 0; i < 32; i++) {
		if (__atexit_fvec[i] == NULL) {
			__atexit_fvec[i] = func;
			__atexit_fvec[i + 1] = NULL;
			return 0;
		}
	}

	return -1;
}
