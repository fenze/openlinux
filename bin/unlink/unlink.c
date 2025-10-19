#include <stdio.h>
#include <unistd.h>

static void usage(void)
{
	write(STDERR_FILENO, "usage: unlink file\n", 10);
}

int main(int argc, char **argv)
{
	char opt;

	while ((opt = getopt(argc, argv, "")) != -1) {
		switch (opt) {
		default:
			usage();
			return 1;
		}
	}

	if (argc != 2) {
		usage();
		return 1;
	}

	if (unlink(argv[1]) == -1) {
		perror("unlink: ");
		return 1;
	}

	_exit(0);
}
