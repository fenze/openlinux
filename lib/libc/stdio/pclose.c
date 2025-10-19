#include <io.h>
#include <stdio.h>
#include <sys/wait.h>

int pclose(FILE *stream)
{
	int stat;
	fclose(stream);
	return (waitpid(stream->pid, &stat, 0) < 0) ? -1 : stat;
}
