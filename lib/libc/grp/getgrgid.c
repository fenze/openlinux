#include <grp.h>       // for getgrgid_r, getgrgid, group
#include <limits.h>    // for LINE_MAX
#include <stddef.h>    // for NULL
#include <sys/types.h> // for gid_t

struct group *getgrgid(gid_t gid)
{
	static struct group grp;
	static char buf[LINE_MAX * 2];
	struct group *res;

	if (getgrgid_r(gid, &grp, buf, sizeof(buf), &res) != 0)
		return NULL;

	return res;
}
