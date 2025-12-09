#include <fcntl.h>    // for AT_FDCWD
#include <sys/stat.h> // for fstatat, stat

int stat(const char *restrict path, struct stat *restrict buf)
{
	return fstatat(AT_FDCWD, path, buf, 0);
}
