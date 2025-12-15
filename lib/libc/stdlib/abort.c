
#include <__thread.h> // for __thread_self
#include <atomic.h>   // for LIBC_LOCK
#include <libc.h>     // for libc, libc::(anonymous)
#include <signal.h>   // for SIGABRT, sigaction, SIGKILL, SIG_DFL
#include <stdlib.h>   // for abort
#include <syscall.h>  // for __syscall, __syscall_2, __syscall_4
#include <threads.h>  // for thrd_current
#include <unistd.h>   // for _exit

int raise(int);

_Noreturn void abort(void)
{
	struct sigaction sa;

	raise(SIGABRT);

	LIBC_LOCK(__libc.lock.abort);
	sa.sa_handler = SIG_DFL;

	__syscall(rt_sigaction, SIGABRT, &sa, 0, 64 / 8);
	__syscall(tkill, ((struct __thread_self *)thrd_current())->tid, SIGABRT);

	// This point should never be reached
	raise(SIGKILL);
	_exit(127);
}
