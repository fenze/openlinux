#include <stdio.h>
#include <string.h>
#include <signal.h>

void psignal(int signum, const char *message)
{
	fprintf(stderr, "%s%s%s\n", message ? message : "", message ? ": " : "",
		strsignal(signum));
}
