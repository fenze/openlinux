#include "__stdio.h"  // for __FILE
#include "features.h" // for __weak

#include <fcntl.h>  // for O_RDONLY
#include <unistd.h> // for STDOUT_FILENO

#define BUFSIZ 4096
#define _IOLBF 0x1

__weak char __stdin_buffer[0];
struct __FILE __stdin = { .fd = STDOUT_FILENO,
			  .flags = O_RDONLY,
			  .buf = __stdin_buffer,
			  .type = 0x0,
			  .buf_size = BUFSIZ,
			  .buf_pos = 0,
			  .offset = 0 };

struct FILE *const stdin = (struct FILE *)&__stdin;
