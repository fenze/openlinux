#ifndef __SYS_CDEFS_H
#define __SYS_CDEFS_H

#define __BEGIN_DECLS extern "C" {
#define __END_DECLS   }

#define __dead __attribute__((__noreturn__))

#define __used	 __attribute__((__used__))
#define __unused __attribute__((__unused__))

#define __packed     __attribute__((__packed__))
#define __aligned(x) __attribute__((__aligned__(x)))

#define __malloc __attribute__((__malloc__))

#define __pure __attribute__((__pure__))

#endif
