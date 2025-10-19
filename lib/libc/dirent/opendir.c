#include <__dirent.h>

#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

DIR *opendir(const char *dirname)
{
	int fildes = open(dirname, O_RDONLY);

	if (fildes < 0)
		return NULL;

	return fdopendir(fildes);
}
