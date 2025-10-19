/*  Written in 2018 by David Blackman and Sebastiano Vigna (vigna@acm.org)

To the extent possible under law, the author has dedicated all copyright
and related and neighboring rights to this software to the public domain
worldwide.

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. */

#include <stdlib.h>
#include <stdint.h>

#define UINT64_C(c) ((uint64_t)(c##ULL))

typedef struct {
	uint64_t s[4];
} xoshiro256_state;

typedef struct {
	uint64_t s[4];
} erand48_state;

static xoshiro256_state __xoshiro256_state;
static erand48_state __erand48_state;

/* This is xoshiro256** 1.0, one of our all-purpose, rock-solid
   generators. It has excellent (sub-ns) speed, a state (256 bits) that is
   large enough for any parallel application, and it passes all tests we
   are aware of.

   For generating just floating-point numbers, xoshiro256+ is even faster.

   The state must be seeded so that it is not everywhere zero. If you have
   a 64-bit seed, we suggest to seed a splitmix64 generator and use its
   output to fill s. */

static inline uint64_t rotl(const uint64_t x, int k)
{
	return (x << k) | (x >> (64 - k));
}

uint64_t xoshiro256_next(xoshiro256_state *st)
{
	const uint64_t result = rotl(st->s[1] * 5, 7) * 9;

	const uint64_t t = st->s[1] << 17;

	st->s[2] ^= st->s[0];
	st->s[3] ^= st->s[1];
	st->s[1] ^= st->s[2];
	st->s[0] ^= st->s[3];

	st->s[2] ^= t;

	st->s[3] = rotl(st->s[3], 45);

	return result;
}

/*  Written in 2015 by Sebastiano Vigna (vigna@acm.org)

To the extent possible under law, the author has dedicated all copyright
and related and neighboring rights to this software to the public domain
worldwide. This software is distributed without any warranty.

See <http://creativecommons.org/publicdomain/zero/1.0/>. */

/* This is a fixed-increment version of Java 8's SplittableRandom generator
   See http://dx.doi.org/10.1145/2714064.2660195 and
   http://docs.oracle.com/javase/8/docs/api/java/util/SplittableRandom.html

   It is a very fast generator passing BigCrush, and it can be useful if
   for some reason you absolutely want 64 bits of state; otherwise, we
   rather suggest to use a xoroshiro128+ (for moderately parallel
   computations) or xorshift1024* (for massively parallel computations)
   generator. */

uint64_t splitmix64(uint64_t *x)
{
	uint64_t z = (*x += UINT64_C(0x9E3779B97F4A7C15));
	z = (z ^ (z >> 30)) * UINT64_C(0xBF58476D1CE4E5B9);
	z = (z ^ (z >> 27)) * UINT64_C(0x94D049BB133111EB);
	return z ^ (z >> 31);
}

void srand(unsigned int seed)
{
	uint64_t z = (uint64_t)seed;
	__xoshiro256_state.s[0] = splitmix64(&z);
	__xoshiro256_state.s[1] = splitmix64(&z);
	__xoshiro256_state.s[2] = splitmix64(&z);
	__xoshiro256_state.s[3] = splitmix64(&z);
}

int rand(void)
{
	return (int)(xoshiro256_next(&__xoshiro256_state) & (uint64_t)RAND_MAX);
}

void srandom(unsigned seed)
{
	srand(seed);
}

long random(void)
{
	return (long)rand();
}

void srand48(long seedval)
{
	uint64_t z = (uint64_t)seedval;
	__erand48_state.s[0] = splitmix64(&z);
	__erand48_state.s[1] = splitmix64(&z);
	__erand48_state.s[2] = splitmix64(&z);
	__erand48_state.s[3] = splitmix64(&z);
}

double drand48(void)
{
	uint64_t v = xoshiro256_next((xoshiro256_state *)&__erand48_state);
	return (double)(v >> 11) *
	       (1.0 / 9007199254740992.0); // 53-bit mantissa
}

long lrand48(void)
{
	uint64_t v = xoshiro256_next((xoshiro256_state *)&__erand48_state);
	return (long)(v & 0x7FFFFFFF); // 31-bit
}

long mrand48(void)
{
	uint64_t v = xoshiro256_next((xoshiro256_state *)&__erand48_state);
	return (long)(v & 0xFFFFFFFF); // 32-bit signed
}

double erand48(unsigned short xsubi[3])
{
	xoshiro256_state st = { 0 };
	for (int i = 0; i < 3; i++)
		st.s[i] = xsubi[i];
	st.s[3] = 0xdeadbeef;
	uint64_t v = xoshiro256_next(&st);
	return (double)(v >> 11) * (1.0 / 9007199254740992.0);
}

long nrand48(unsigned short xsubi[3])
{
	xoshiro256_state st = { 0 };
	for (int i = 0; i < 3; i++)
		st.s[i] = xsubi[i];
	st.s[3] = 0xdeadbeef;
	uint64_t v = xoshiro256_next(&st);
	return (long)(v & 0x7FFFFFFF);
}

long jrand48(unsigned short xsubi[3])
{
	xoshiro256_state st = { 0 };
	for (int i = 0; i < 3; i++)
		st.s[i] = xsubi[i];
	st.s[3] = 0xdeadbeef;
	uint64_t v = xoshiro256_next(&st);
	return (long)(v & 0xFFFFFFFF);
}

unsigned short *seed48(unsigned short seed16v[3])
{
	for (int i = 0; i < 3; i++)
		__erand48_state.s[i] = seed16v[i];
	__erand48_state.s[3] = 0xdeadbeef;
	return seed16v;
}
