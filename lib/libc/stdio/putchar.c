#include <libc.h>  // for weak_reference
#include <stdio.h> // for putc, putchar, putchar_unlocked, stdout

int putchar(int c)
{
	return putc(c, stdout);
}

weak_reference(putchar, putchar_unlocked);
