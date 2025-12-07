#ifndef __BITS_WAIT_H
#define __BITS_WAIT_H

#ifndef __BITS_WAIT_H_
#error "Internal header — include the public API header instead."
#else
#undef __BITS_WAIT_H_
#endif

#define WNOHANG	  0x00000001
#define WUNTRACED 0x00000002

#define WEXITSTATUS(__status) (((__status) & 0xff00) >> 8)
#define WCOREDUMP(__status)   ((__status) & 0x80)
#define WTERMSIG(__status)    ((__status) & 0x7f)
#define WSTOPSIG(__status)    WEXITSTATUS(__status)
#define WIFEXITED(__status)   (WTERMSIG(__status) == 0)
#define WIFSTOPPED(__status)  (((__status) & 0xff) == 0x7f)
#define WIFSIGNALED(__status) (((__status) & 0xffff) - 1U < 0xffu)
#define WSTOPSIG(__status)    WEXITSTATUS(__status)

#endif
