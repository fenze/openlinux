#include <__stdio.h>  // for __FILE
#include <stdio.h>    // for fclose, FILE, pclose
#include <sys/wait.h> // for waitpid

int pclose(FILE *stream)
{
	int stat;
	fclose(stream);
	return (waitpid(__FILE(stream)->pid, &stat, 0) < 0) ? -1 : stat;
}
