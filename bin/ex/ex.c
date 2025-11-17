#include <unistd.h>

int main(int argc, char **argv)
{
	write(STDERR_FILENO, "usage: ex\n", 10);
	return 0;
}

