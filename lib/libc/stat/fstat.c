#include <sys/stat.h> // for fstatat, fstat

int fstat(int fildes, struct stat *buf)
{
	return fstatat(fildes, "", buf, 0);
}
