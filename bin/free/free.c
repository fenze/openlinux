#include <stdio.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int opt;
	struct sysinfo info;
	unsigned int shift;

	while ((opt = getopt(argc, argv, "hmtbs")) != -1) {
		switch (opt) {
		case 'b': /* bytes */
			shift = 0;
			break;
		case 'k': /* kibibytes */
			shift = 10;
			break;
		case 'm': /* mebibytes */
			shift = 20;
			break;
		case 'g': /* gibibytes */
			shift = 30;
			break;
		default:
			goto usage;
		}
	}

	if (sysinfo(&info) < 0)
		perror("sysinfo");

	printf("     %13s%13s%13s%13s%13s\n", "total", "used", "free", "shared",
	       "buffers");

	printf("Mem: %13llu%13llu%13llu%13llu%13llu\n",
	       (unsigned long long)((info.totalram * info.mem_unit) >> shift),
	       (unsigned long long)(((info.totalram - info.freeram) *
				     info.mem_unit) >>
				    shift),
	       (unsigned long long)((info.freeram * info.mem_unit) >> shift),
	       (unsigned long long)((info.sharedram * info.mem_unit) >> shift),
	       (unsigned long long)((info.bufferram * info.mem_unit) >> shift));

	printf("-/+ buffers/cache:%13llu%13llu\n",
	       (unsigned long long)(((info.totalram - info.freeram -
				      info.bufferram) *
				     info.mem_unit) >>
				    shift),
	       (unsigned long long)(((info.freeram + info.bufferram) *
				     info.mem_unit) >>
				    shift));
	printf("Swap:%13llu%13llu%13llu\n",
	       (unsigned long long)((info.totalswap * info.mem_unit) >> shift),
	       (unsigned long long)(((info.totalswap - info.freeswap) *
				     info.mem_unit) >>
				    shift),
	       (unsigned long long)((info.freeswap * info.mem_unit) >> shift));

	return 0;
usage:
	write(STDOUT_FILENO, "usage: free [-hmtbs]\n", 21);
	return 0;
}
