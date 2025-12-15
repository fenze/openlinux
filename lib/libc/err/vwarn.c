#include "stddef.h"
#include <stdarg.h>
#include <stdio.h>

extern char *__progname;

void vwarn(const char *fmt, va_list args)
{
	fprintf(stderr, "%s: ", __progname);

	if (fmt != NULL) {
		vfprintf(stderr, fmt, args);
		fprintf(stderr, ": ");
	}

	perror(NULL);
}
