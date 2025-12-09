#include <dirent.h> // for DIR, dirfd
#include <stdint.h> // for intptr_t

int dirfd(DIR *dirp)
{
	return ~((intptr_t)dirp);
}
