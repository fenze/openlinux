#include <io.h>
#include <atomic.h>
#include <stdio.h>
#include <unistd.h>

off_t ftello(FILE *stream)
{
	return fseek(stream, 0, SEEK_CUR);
}
