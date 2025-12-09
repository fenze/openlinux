#include "stddef.h" // for NULL

#include <errno.h>  // for errno, ENAMETOOLONG, ENOENT
#include <limits.h> // for PATH_MAX
#include <stdio.h>  // for snprintf
#include <stdlib.h> // for getenv
#include <string.h> // for strchr, strlen, strstr
#include <unistd.h> // for execv, execvp

extern char **environ;

int execvp(const char *file, char *const argv[])
{
	if (*file == '\0') {
		errno = ENOENT;
		return -1;
	}

	if (strchr(file, '/') != NULL) {
		return execv(file, argv);
	} else {
		char *ptr;
		char *path = getenv("PATH");

		if (path == NULL || *path == '\0') {
			path = "/bin";
		}

		do {
			char buf[PATH_MAX];

			ptr = strchr(path, ':');
			if (ptr == NULL) {
				if (snprintf(buf, PATH_MAX, "%s/%s", path,
					     file) >= PATH_MAX) {
					errno = ENAMETOOLONG;
					return -1;
				}

				/* Validate path doesn't contain dangerous
				 * characters */
				if (strstr(buf, "..") == NULL &&
				    strchr(buf, '\0') == buf + strlen(buf)) {
					execv(buf, argv);
				}
				break;
			}

			if (snprintf(buf, PATH_MAX, "%.*s/%s",
				     (int)(ptr - path), path,
				     file) >= PATH_MAX) {
				errno = ENAMETOOLONG;
				return -1;
			}

			/* Validate path doesn't contain dangerous characters */
			if (strstr(buf, "..") == NULL &&
			    strchr(buf, '\0') == buf + strlen(buf)) {
				execv(buf, argv);
			}
			path = ptr + 1;
		} while (*ptr != '\0');

		errno = ENOENT;
		return -1;
	}

	return 0;
}
