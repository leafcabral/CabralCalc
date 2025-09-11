#include "../include/utils.h"

#include <stdio.h>
#include <stdlib.h>

void *salloc(size_t size) {
	void *mem = malloc(size);
	if (!mem) {
		panic("Failed to allocate memory");
	} else {
		return mem;
	}
}
