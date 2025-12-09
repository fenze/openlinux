#include <__stdio.h> // for __FILE
#include <stdio.h>   // for fflush, FILE, fclose, stderr, stdin, stdout
#include <unistd.h>  // for close

int fclose(FILE *stream)
{
	if (fflush(stream) == -1)
		return -1;

	if (stream != stdin && stream != stdout && stream != stderr) {
		if (close((__FILE(stream))->fd) == -1)
			return -1;
	}

	return 0;
}
