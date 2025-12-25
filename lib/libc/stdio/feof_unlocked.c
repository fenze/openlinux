#include <__stdio.h>
#include <stdio.h>

int feof_unlocked(FILE *stream)
{
	return (stream) ? ((struct __FILE *)stream)->eof : 0;
}
