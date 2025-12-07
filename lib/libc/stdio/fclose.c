#include <io.h>
#include <stdio.h>
#include <unistd.h>

int fclose(FILE *stream)
{
	if (fflush(stream) == -1)
		return -1;

	if (stream != stdin && stream != stdout && stream != stderr) {
		if (close(stream->fd) == -1)
			return -1;
	}

	return 0;
}
