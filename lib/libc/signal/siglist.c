#include <signal.h>

const char *const sys_siglist[64] = {
	[SIGABRT] = "Aborted",
	[SIGALRM] = "Alarm clock",
	[SIGBUS] = "Bus error",
	[SIGCHLD] = "Child exited",
#if defined(SIGCLD) && (SIGCHLD != SIGCLD)
	[SIGCLD] = "Child exited",
#endif
	[SIGHUP] = "Hangup",
	[SIGILL] = "Illegal instruction",
	[SIGINT] = "Interrupt",
	[SIGIO] = "I/O possible",
#if defined(SIGIOT) && (SIGIOT != SIGABRT)
	[SIGIOT] = "I/O trap",
#endif
	[SIGKILL] = "Killed",
#if defined(SIGLOST) && (SIGLOST != SIGIO) && (SIGLOST != SIGPWR)
	[SIGLOST] = "Lock lost",
#endif
	[SIGPIPE] = "Broken pipe",
#if defined(SIGPOLL) && (SIGPOLL != SIGIO)
	[SIGPOLL] = "Pollable event",
#endif
	[SIGPROF] = "Profiling timer expired",
	[SIGPWR] = "Power failure",
	[SIGQUIT] = "Quit",
	[SIGSEGV] = "Segment violation",
	[SIGSTKFLT] = "Stack fault",
	[SIGSTOP] = "Stopped (signal)",
	[SIGSYS] = "Bad system call",
	[SIGTERM] = "Terminated",
	[SIGTSTP] = "Stopped",
	[SIGTTIN] = "Stopped (tty input)",
	[SIGTTOU] = "Stopped (tty output)",
	[SIGURG] = "Urgent I/O condition",
	[SIGUSR1] = "User signal 1",
	[SIGUSR2] = "User signal 2",
	[SIGVTALRM] = "Virtual timer expired",
	[SIGWINCH] = "Window size changed",
	[SIGXCPU] = "CPU time limit exceeded",
	[SIGXFSZ] = "File size limit exceeded",
	[SIGTRAP] = "Trace/breakpoint trap",
	[SIGCONT] = "Continue",
};
