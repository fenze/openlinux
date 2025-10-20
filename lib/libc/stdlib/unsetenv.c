#include <errno.h>
#include <string.h>
#include <stdlib.h>

int unsetenv(const char *name)
{
	if (name == NULL || *name == '\0' || strchr(name, '=')) {
		errno = EINVAL;
		return -1;
	}

	return setenv(name, NULL, 1);
}
