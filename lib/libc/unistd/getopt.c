#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/uio.h>

char *optarg;
int optind = 1, opterr = 1, optopt;

int getopt(int argc, char *const argv[], const char *optstring)
{
	char *optchar;
	char c, d;
	int i;
	static int optpos;

	if (optind == 0) {
		optpos = 0;
		optind = 1;
	}

	if (optind >= argc || !argv[optind]) {
		return -1;
	}

	if (argv[optind][0] != '-') {
		if (optstring[0] == '-') {
			optarg = argv[optind++];
			return 1;
		}

		return -1;
	}

	if (argv[optind][1] == 0) {
		return -1;
	}

	if (argv[optind][1] == '-' && argv[optind][2] == 0) {
		return optind++, -1;
	}

	if (optpos == 0)
		optpos++;

	c = argv[optind][optpos];
	optchar = argv[optind] + optpos++;

	if (argv[optind][optpos] == 0) {
		optind++;
		optpos = 0;
	}

	i = 0;

	do {
		d = optstring[i++];
	} while (d && d != c);

	if (d != c || c == ':') {
		optopt = c;
		if (optstring[0] != ':' && opterr) {
			struct iovec iov[4];
			char opt_char[2] = { *optchar, '\0' };

			iov[0].iov_base = argv[0];
			iov[0].iov_len = strlen(argv[0]);
			iov[1].iov_base = ": invalid option -- ";
			iov[1].iov_len = 20;
			iov[2].iov_base = opt_char;
			iov[2].iov_len = 1;
			iov[3].iov_base = "\n";
			iov[3].iov_len = 1;

			writev(STDERR_FILENO, iov, 4);
		}
		return '?';
	}

	if (optstring[i] == ':') {
		optarg = 0;
		if (optstring[i + 1] != ':' || optpos) {
			optarg = argv[optind++];
			if (optpos) {
				optarg += optpos;
			}
			optpos = 0;
		}
		if (optind > argc) {
			optopt = c;
			if (optstring[0] == ':') {
				return ':';
			}
			if (opterr) {
				struct iovec iov[4];
				char opt_char[2] = { *optchar, '\0' };

				iov[0].iov_base = argv[0];
				iov[0].iov_len = strlen(argv[0]);
				iov[1].iov_base =
					": option requires an argument -- ";
				iov[1].iov_len = 33;
				iov[2].iov_base = opt_char;
				iov[2].iov_len = 1;
				iov[3].iov_base = "\n";
				iov[3].iov_len = 1;

				writev(STDERR_FILENO, iov, 4);
			}
			return '?';
		}
	}

	return c;
}
