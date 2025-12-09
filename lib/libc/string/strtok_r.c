#include <string.h> // for NULL, strchr, strtok_r

char *strtok_r(char *restrict s, const char *restrict sep,
	       char **restrict state)
{
	if (s == NULL) {
		s = *state;
	}

	if (s == NULL) {
		return NULL;
	}

	while (*s && strchr(sep, *s)) {
		s++;
	}

	if (*s == '\0') {
		*state = NULL;
		return NULL;
	}

	char *start = s;

	while (*s && strchr(sep, *s) == NULL) {
		s++;
	}

	if (*s) {
		*s = '\0';
		*state = s + 1;
	} else {
		*state = NULL;
	}

	return start;
}
