#include <fcntl.h>    // for AT_FDCWD, AT_SYMLINK_NOFOLLOW
#include <sys/stat.h> // for fstatat, lstat

int lstat(const char *restrict path, struct stat *restrict buf)
{
	return fstatat(AT_FDCWD, path, buf, AT_SYMLINK_NOFOLLOW);
}
