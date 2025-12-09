#include <signal.h>
#include <unistd.h>

const char *const sys_sigabbrev[64] = {
	[SIGABRT] = "ABRT",   [SIGALRM] = "ALRM",     [SIGBUS] = "BUS",
	[SIGCHLD] = "CHLD",   [SIGFPE] = "FPE",	      [SIGHUP] = "HUP",
	[SIGILL] = "ILL",     [SIGINT] = "INT",	      [SIGIO] = "IO",
#if defined(SIGIOT) && (SIGIOT != SIGABRT)
	[SIGIOT] = "IOT",
#endif
	[SIGKILL] = "KILL",   [SIGPIPE] = "PIPE",
#if defined(SIGPOLL) && (SIGPOLL != SIGIO)
	[SIGPOLL] = "POLL",
#endif
	[SIGPROF] = "PROF",   [SIGPWR] = "PWR",	      [SIGQUIT] = "QUIT",
	[SIGSEGV] = "SEGV",   [SIGSTKFLT] = "STKFLT", [SIGSTOP] = "STOP",
	[SIGSYS] = "SYS",     [SIGTERM] = "TERM",     [SIGTSTP] = "TSTP",
	[SIGTTIN] = "TTIN",   [SIGTTOU] = "TTOU",     [SIGURG] = "URG",
	[SIGUSR1] = "USR1",   [SIGUSR2] = "USR2",     [SIGVTALRM] = "VTALRM",
	[SIGWINCH] = "WINCH", [SIGXCPU] = "XCPU",     [SIGXFSZ] = "XFSZ",
	[SIGCONT] = "CONT",   [SIGTRAP] = "TRAP",
};
