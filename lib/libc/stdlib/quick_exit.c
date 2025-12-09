#include <stdlib.h> // for _Exit, quick_exit

_Noreturn void quick_exit(int status)
{
	_Exit(status);
}
