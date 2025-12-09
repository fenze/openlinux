#include "stddef.h" // for NULL

#include <string.h> // for strchr, strtok

char *strtok(char *restrict s, const char *restrict sep)
{
	static _Thread_local char *state = NULL;

	if (s != NULL) {
		state = s;
	}

	if (state == NULL) {
		return NULL;
	}

	char *token = state;
	while (*token && strchr(sep, *token)) {
		token++;
	}

	if (*token == '\0') {
		state = NULL;
		return NULL;
	}

	char *start = token;

	while (*token && strchr(sep, *token) == NULL) {
		token++;
	}

	if (*token) {
		*token = '\0';
		state = token + 1;
	} else {
		state = NULL;
	}

	return start;
}
