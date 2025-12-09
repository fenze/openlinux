


#include <signal.h>    // for siginfo_t
#include <sys/types.h> // for id_t
#include <sys/wait.h>  // for idtype_t, waitid
#include <syscall.h>   // for __syscall_4, syscall

int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options)
{
	return syscall(waitid, idtype, id, infop, options);
}
