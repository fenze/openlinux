#ifndef __SYS_CDEFS_H
#define __SYS_CDEFS_H

#ifdef __cplusplus
#define __BEGIN_DECLS extern "C" {
#define __END_DECLS   }
#else
#define __BEGIN_DECLS
#define __END_DECLS
#endif

#define __dead	     __attribute__((__noreturn__))
#define __used	     __attribute__((__used__))
#define __unused     __attribute__((__unused__))
#define __packed     __attribute__((__packed__))
#define __aligned(x) __attribute__((__aligned__(x)))
#define __malloc     __attribute__((__malloc__))
#define __pure	     __attribute__((__pure__))
#define __nodiscard  __attribute__((__warn_unused_result__))
#define __weak	     __attribute__((__weak__))

#define __predict_true(exp)  __builtin_expect((exp) != 0, 1)
#define __predict_false(exp) __builtin_expect((exp) != 0, 0)

#endif
