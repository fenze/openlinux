#include <stdint.h> // for intmax_t

intmax_t imaxabs(intmax_t j)
{
	return (j < 0) ? -j : j;
}
