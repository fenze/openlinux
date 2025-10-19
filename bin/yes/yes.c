#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	char opt;
	const char *str;

	while ((opt = getopt(argc, argv, "")) != -1) {
		switch (opt) {
		default:
			write(2, "usage: yes [expletive]\n", 18);
			return 1;
		}
	}

	str = (argc > 1) ? argv[1] : "y";

	while (1) {
		write(1, str, strlen(str));
		write(1, "\n", 1);
	}

	return 0;
}
