#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	char opt;

	while ((opt = getopt(argc, argv, "")) != -1) {
		switch (opt) {
		default:
			goto usage;
			return 1;
		}
	}

	if (argc != 2) {
		goto usage;
		return 1;
	}

	if (unlink(argv[1]) == -1) {
		perror("unlink: ");
		return 1;
	}

	return 0;
usage:
	write(STDERR_FILENO, "usage: unlink file\n", 10);
	return 0;
}
