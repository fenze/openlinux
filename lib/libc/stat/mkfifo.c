#include <sys/stat.h>  // for mknod, S_IFIFO, mkfifo
#include <sys/types.h> // for mode_t

int mkfifo(const char *path, mode_t mode)
{
	return mknod(path, mode | S_IFIFO, 0);
}
