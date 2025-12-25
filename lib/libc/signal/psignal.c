#include <signal.h> // for psignal
#include <stdio.h>  // for fprintf, stderr
#include <string.h> // for strsignal

void psignal(int signum, const char *message)
{
	fprintf(stderr, "%s%s%s\n", message ? message : "", message ? ": " : "", strsignal(signum));
}
