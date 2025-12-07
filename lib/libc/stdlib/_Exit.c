#include <unistd.h>

_Noreturn void _Exit(int status)
{
	_exit(status);
}
