#include <unistd.h>

int main(void)
{
	write(STDOUT_FILENO, "\033[H\033[2J", 7);
	_exit(0);
}
