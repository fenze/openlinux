#include <stdlib.h>

_Noreturn void quick_exit(int status)
{
	_Exit(status);
}
