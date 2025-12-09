#include <signal.h> // for kill, raise
#include <unistd.h> // for getpid

int raise(int sig)
{
	return kill(getpid(), sig);
}
