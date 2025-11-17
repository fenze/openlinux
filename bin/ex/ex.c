#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	write(STDERR_FILENO, "usage: ex\n", 10);
	return 0;
}

