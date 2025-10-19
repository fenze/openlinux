#include <stdint.h>

intmax_t imaxabs(intmax_t j)
{
	return (j < 0) ? -j : j;
}
