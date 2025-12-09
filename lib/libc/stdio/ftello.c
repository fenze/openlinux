#include <stdio.h>     // for fseek, FILE, SEEK_CUR, ftello
#include <sys/types.h> // for off_t

off_t ftello(FILE *stream)
{
	return fseek(stream, 0, SEEK_CUR);
}
