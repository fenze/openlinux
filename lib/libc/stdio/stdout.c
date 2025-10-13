#include <io.h>
#include <unistd.h>

#define BUFSIZ 4096

static char __stdout_buffer[BUFSIZ];
struct __FILE __stdout = { .fd = STDOUT_FILENO,
			   .flags = _IO_WRITE,
			   .buf = __stdout_buffer,
			   .type = 0x1,
			   .buf_size = BUFSIZ,
			   .buf_pos = 0,
			   .offset = 0 };

struct FILE *const stdout = (struct FILE *)&__stdout;
