#ifndef __LIBC_SIGNAL_H
#define __LIBC_SIGNAL_H

static const char *__sys_signame[] = { "SIGHUP",    "SIGINT",  "SIGQUIT",  "SIGILL",  "SIGTRAP", "SIGABRT",
				       "SIGBUS",    "SIGFPE",  "SIGKILL",  "SIGUSR1", "SIGSEGV", "SIGUSR2",
				       "SIGPIPE",   "SIGALRM", "SIGTERM",  "SIGCHLD", "SIGCONT", "SIGSTOP",
				       "SIGTSTP",   "SIGTTIN", "SIGTTOU",  "SIGURG",  "SIGXCPU", "SIGXFSZ",
				       "SIGVTALRM", "SIGPROF", "SIGWINCH", "SIGIO",   "SIGSYS" };

#endif
