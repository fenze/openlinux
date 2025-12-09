#include <signal.h> // for sigemptyset, sigset_t

int sigemptyset(sigset_t *set)
{
	if (!set)
		return -1;
	*set = 0;

	return 0;
}
