#include <stdio.h>  // for fwrite, stdout, puts
#include <string.h> // for strlen

int puts(const char *s)
{
	fwrite(s, 1, strlen(s), stdout);
	fwrite("\n", 1, 1, stdout);
	return 0;
}
