#include "stddef.h" // for NULL

#include <libc.h>  // for weak_reference
#include <stdio.h> // for fread, FILE, fgets

char *fgets(char *restrict s, int n, FILE *restrict stream)
{
	return fread(s, 1, n, stream) ? s : NULL;
}

weak_reference(fgets, fgets_unlocked);
