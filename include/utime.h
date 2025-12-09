#ifndef __UTIME_H
#define __UTIME_H

struct utimbuf {
	long actime;
	long modtime;
};

int utime(const char *, const struct utimbuf *);

#endif
