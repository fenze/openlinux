#include <sys/wait.h>
#include <syscall.h>

int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options)
{
	return syscall(waitid, idtype, id, infop, options);
}
