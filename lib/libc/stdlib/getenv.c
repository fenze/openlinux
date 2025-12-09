#include <atomic.h> // for LIBC_UNLOCK, LIBC_LOCK
#include <libc.h>   // for (anonymous struct)::(anonymous), (anonymous), libc
#include <stddef.h> // for NULL
#include <stdlib.h> // for getenv, secure_getenv

extern char **environ;

char *getenv(const char *name)
{
	LIBC_LOCK(libc.lock.environ);

	for (char **env = environ; *env; env++) {
		char *eq = NULL;
		for (char *p = *env; *p; p++) {
			if (*p == '=') {
				eq = p;
				break;
			}
			if (name[p - *env] != *p) {
				break;
			}
		}
		if (eq && name[eq - *env] == '\0') {
			LIBC_UNLOCK(libc.lock.environ);
			return eq + 1;
		}
	}

	LIBC_UNLOCK(libc.lock.environ);

	return NULL;
}

weak_reference(getenv, secure_getenv);
