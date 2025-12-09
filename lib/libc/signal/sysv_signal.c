#include <signal.h> // for sigaction, sigemptyset, sighandler_t, SIG_ERR

sighandler_t sysv_signal(int signum, sighandler_t handler)
{
	struct sigaction new_action, old_action;

	new_action.sa_handler = handler;
	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = 0;

	if (sigaction(signum, &new_action, &old_action) < 0)
		return SIG_ERR;

	return old_action.sa_handler;
}
