#include <stdlib.h>
#include <wchar.h>
#include <stdio.h>

#define IS_CODEUNIT(c) ((unsigned)(c) - 0xdf80 < 0x80)

int wctob(wint_t c)
{
	if (c < 128U)
		return (int)c;

	if (MB_CUR_MAX == 1 && IS_CODEUNIT(c))
		return (unsigned char)c;

	return EOF;
}
