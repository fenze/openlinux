#include <err.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	double seconds;
	struct timespec ts;

	if (argc != 2) {
		write(1, "usage: sleep seconds\n", 21);
		return 0;
	}

	seconds = strtod(argv[1], NULL);
	ts.tv_sec = (time_t)seconds;
	ts.tv_nsec = (long)((seconds - (double)ts.tv_sec) * 1e9);

	if (nanosleep(&ts, NULL) < 0)
		err(1, "nanosleep");

	return 0;
}
