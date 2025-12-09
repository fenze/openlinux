#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define CODEUNIT(c) (0xdfff & (signed char)(c))

wint_t btowc(int c)
{
	if ((unsigned char)c < 128U) {
		return c;
	}

	if (MB_CUR_MAX == 1 && c != EOF) {
		return CODEUNIT(c);
	}

	return WEOF;
}
