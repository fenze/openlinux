#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	extern char **environ;
	char **p;

	p = environ;
	while (*p) {
		write(STDOUT_FILENO, *p, strlen(*p));
		write(STDOUT_FILENO, "\n", 1);
	}
}
