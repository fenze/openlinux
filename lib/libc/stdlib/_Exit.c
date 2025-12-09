#include <unistd.h> // for _exit

_Noreturn void _Exit(int status)
{
	_exit(status);
}
