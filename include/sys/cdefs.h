#ifndef __SYS_CDEFS_H
#define __SYS_CDEFS_H

#ifdef __cplusplus
#define __BEGIN_DECLS extern "C" {
#define __END_DECLS   }
#else
#define __BEGIN_DECLS
#define __END_DECLS
#endif

#define ___STRING(x) #x
#define __STRING(x)  ___STRING(x)

#define __dead	     __attribute__((__noreturn__))
#define __used	     __attribute__((__used__))
#define __unused     __attribute__((__unused__))
#define __packed     __attribute__((__packed__))
#define __aligned(x) __attribute__((__aligned__(x)))
#define __malloc     __attribute__((__malloc__))
#define __pure	     __attribute__((__pure__))
#define __nodiscard  __attribute__((__warn_unused_result__))
#undef __weak
#define __weak	__attribute__((__weak__))
#define __naked __attribute__((__naked__))
#define __const __attribute__((__const__))

#define __predict_true(exp)  __builtin_expect((exp) != 0, 1)
#define __predict_false(exp) __builtin_expect((exp) != 0, 0)

#define __INT128_TYPE__	 __int128
#define __UINT128_TYPE__ unsigned __INT128_TYPE__

typedef __INT8_TYPE__ i8;
typedef __INT16_TYPE__ i16;
typedef __INT32_TYPE__ i32;
typedef __INT64_TYPE__ i64;
typedef __INT128_TYPE__ i128;

typedef __UINT8_TYPE__ u8;
typedef __UINT16_TYPE__ u16;
typedef __UINT32_TYPE__ u32;
typedef __UINT64_TYPE__ u64;
typedef __UINT128_TYPE__ u128;

typedef _Float16 f16;
typedef float f32;
typedef double f64;
typedef __float128 f128;

#endif
