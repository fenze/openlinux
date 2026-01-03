#pragma once

typedef __SIZE_TYPE__ size_t;

int posix_devctl(int, int, void *restrict, size_t, int *restrict);
