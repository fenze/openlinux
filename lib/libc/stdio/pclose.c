#include <__stdio.h>
#include <stdio.h>    // for fclose, FILE, pclose
#include <sys/wait.h> // for waitpid

int pclose(struct __FILE *stream)
{
	int stat;
	fclose(stream);
	return (waitpid(stream->pid, &stat, 0) < 0) ? -1 : stat;
}
