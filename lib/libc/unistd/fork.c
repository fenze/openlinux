#include <unistd.h> // for _Fork, fork, pid_t

pid_t fork(void)
{
	return _Fork();
}
