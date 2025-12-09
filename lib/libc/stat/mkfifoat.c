#include <sys/stat.h>  // for mknodat, S_IFIFO, mkfifoat
#include <sys/types.h> // for mode_t

int mkfifoat(int fd, const char *path, mode_t mode)
{
	return mknodat(fd, path, mode | S_IFIFO, 0);
}
