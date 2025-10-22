#include "uefi.h"

static void *__img = NULL;
static struct uefi_system_table *__systbl = NULL;

extern int main(void);

int mbtowc(wchar_t *wc, const char *s, size_t n)
{
	wchar_t arg;
	int ret = 1;
	if (s == NULL || *s == '\0') {
		return 0;
	}

	arg = (wchar_t)*s;

	if ((*s & 128) != 0) {
		if ((*s & 32) == 0 && n > 0) {
			arg = ((*s & 0x1F) << 6) | (*(s + 1) & 0x3F);
			ret = 2;
		} else if ((*s & 16) == 0 && n > 1) {
			arg = ((*s & 0xF) << 12) | ((*(s + 1) & 0x3F) << 6) |
			      (*(s + 2) & 0x3F);
			ret = 3;
		} else if ((*s & 8) == 0 && n > 2) {
			arg = ((*s & 0x7) << 18) | ((*(s + 1) & 0x3F) << 12) |
			      ((*(s + 2) & 0x3F) << 6) | (*(s + 3) & 0x3F);
			ret = 4;
		} else {
			return -1;
		}
	}
	if (wc) {
		*wc = arg;
	}
	return ret;
}

int wctomb(char *s, wchar_t u)
{
	int ret = 0;

	if (u < 0x80) {
		*s = u;
		ret = 1;
	} else if (u < 0x800) {
		*(s + 0) = ((u >> 6) & 0x1F) | 0xC0;
		*(s + 1) = (u & 0x3F) | 0x80;
		ret = 2;
	} else {
		*(s + 0) = ((u >> 12) & 0x0F) | 0xE0;
		*(s + 1) = ((u >> 6) & 0x3F) | 0x80;
		*(s + 2) = (u & 0x3F) | 0x80;
		ret = 3;
	}

	return ret;
}

char *strchr(const char *s, int c)
{
	while (*s) {
		if (*s == (char)c)
			return (char *)s;
		s++;
	}

	if (c == 0) {
		return (char *)s;
	}

	return NULL;
}

ssize_t write(int fd, const void *buf, size_t count)
{
	const char *s;
	uint16_t wbuf[256];
	struct simple_text_output_interface *out;
	size_t i, total;

	if (fd != 1 && fd != 2)
		return -1;

	if (fd == 1) {
		out = __systbl->con_out;
	} else if (fd == 2) {
		out = __systbl->std_err;
	} else {
		return -1;
	}

	s = buf;
	i = total = 0;

	while (i < count) {
		size_t chunk = 0;
		size_t wpos = 0;

		while (i < count && wpos < (sizeof(wbuf) / sizeof(*wbuf)) - 1) {
			wchar_t wc;
			int n = mbtowc(&wc, s + i, count - i);
			if (n < 0)
				break;
			wbuf[wpos++] = (uint16_t)wc;
			i += n;
		}
		wbuf[wpos] = 0;

		out->output_string(out, wbuf);
		total += i;
	}

	return total;
}

uint64_t _start(void *img_handle, struct uefi_system_table *sys_table)
{
	__img = img_handle;
	__systbl = sys_table;

	return main();
}
