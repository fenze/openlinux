#include <stdio.h>
#include <string.h>
#include <errno.h>

void perror(const char *s)
{
	char *errstr = strerror(errno);

	if (s && *s) {
		fwrite(s, strlen(s), 1, stderr);
		fputc(':', stderr);
		fputc(' ', stderr);
	}

	fwrite(errstr, strlen(errstr), 1, stderr);
	fputc('\n', stderr);
}
