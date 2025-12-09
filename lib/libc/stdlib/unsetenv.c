#include "stddef.h" // for NULL

#include <errno.h>  // for EINVAL, errno
#include <stdlib.h> // for setenv, unsetenv
#include <string.h> // for strchr

int unsetenv(const char *name)
{
	if (name == NULL || *name == '\0' || strchr(name, '=')) {
		errno = EINVAL;
		return -1;
	}

	return setenv(name, NULL, 1);
}
