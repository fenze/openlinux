#include <dirent.h> // for fdopendir, DIR, opendir
#include <fcntl.h>  // for open, O_RDONLY
#include <stddef.h> // for NULL

DIR *opendir(const char *dirname)
{
	int fildes = open(dirname, O_RDONLY);

	if (fildes < 0)
		return NULL;

	return fdopendir(fildes);
}
