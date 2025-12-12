#include <sys/cdefs.h>
#include <unistd.h>

int main(int argc, char **__unused argv)
{
	if (argc) {
		write(STDOUT_FILENO, "usage: clear\n", 13);
		return 0;
	}

	write(STDOUT_FILENO, "\033[H\033[2J", 7);

	return 0;
}
