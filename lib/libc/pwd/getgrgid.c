#include <limits.h>    // for LINE_MAX
#include <pwd.h>       // for getpwuid_r, getpwuid, passwd
#include <stddef.h>    // for NULL
#include <sys/types.h> // for uid_t

struct passwd *getpwuid(uid_t uid)
{
	static struct passwd pwd;
	static char buf[LINE_MAX * 4];
	struct passwd *res;

	if (getpwuid_r(uid, &pwd, buf, sizeof(buf), &res) != 0)
		return NULL;

	return res;
}
