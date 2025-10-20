#include <stdlib.h>
#include <string.h>

int putenv(char *string)
{
	const char *const name_end = strchr(string, '=');

	if (name_end) {
		char name[name_end - string + 1];
		memcpy(name, string, name_end - string);
		name[name_end - string] = '\0';
		return setenv(name, name_end + 1, 1);
	}

	unsetenv(string);
	return 0;
}
