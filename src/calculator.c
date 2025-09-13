#include "calculator.h"

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calcInit(Calculator *calc) {
	calc->mem = (typeof(calc->mem)) {0};

	for (int i = 0; i < NUM_HISTORY; i++) {
		calc->buffers[i] = NULL;
	}

	MathExpressionInit(calc->currentExpression);
	
	return 0;
}

int calcClose(Calculator *calc) {
	calc->mem = (typeof(calc->mem)) {0};

	for (int i = 0; i < NUM_HISTORY; i++) {
		free(calc->buffers[i]);
		calc->buffers[i] = NULL;
	}

	mathExpressionFree(calc->currentExpression);
	calc->currentExpression = NULL;
	
	return 0;
}

int calcReadLine(Calculator *calc) {
	// free last -> memmove -> allocate first -> fgets
	free(calc->buffers[NUM_HISTORY - 1]);
	memmove(
		calc->buffers + 1,
		calc->buffers,
		(NUM_HISTORY - 1) * sizeof(char*)
	);
	calc->buffers[0] = salloc(MAX_STR_SIZE * sizeof(char *));

	if (!fgets(calc->buffers[0], MAX_STR_SIZE, stdin)) {
		panic("Failed to read from stdin");
	}
	size_t offset = strcspn(calc->buffers[0], "\r\n");
	calc->buffers[0][offset] = '\0';
	
	return 0;
}

int calcParseLine(Calculator *calc) {
	return 1;
}

float calcLineResult(Calculator *calc) {
	return 1;
}

char *calcCurrentLine(Calculator *calc) {
	return calc->buffers[0];
}

