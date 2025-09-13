#ifndef CABRAL_UTILS_H
#define CABRAL_UTILS_H
#include <stddef.h>

#define MAX_STR_SIZE 128
#define panic(msg) { \
	fprintf(stderr, "PANIC: %s (%s:%d)\n", msg, __FILE__, __LINE__); \
	exit(1); \
}

void *salloc(size_t size);

#endif
