#include <__dirent.h>
#include <dirent.h>

struct dirent *readdir(DIR *dirp)
{
	static struct dirent entry;
	struct dirent *result;
	int err;

	err = readdir_r(dirp, &entry, &result);
	if (err != 0 || result == NULL) {
		return NULL;
	}

	return &entry;
}
