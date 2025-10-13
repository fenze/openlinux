#include <unistd.h>
#include <stdio.h>

void exit(int status)
{
	fflush(stdout);
	_exit(status);
}
