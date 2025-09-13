#ifndef CABRAL_CALCULATOR_H
#define CABRAL_CALCULATOR_H

#define NUM_VARIABLES 9
#define NUM_HISTORY 16

#include "parser.h"

typedef struct {
	union {
		struct { float A, B, C, D, E, F, M, X, Y; };
		float var[NUM_VARIABLES];
	} mem;
	
	char *buffers[NUM_HISTORY];
	MathExpression *currentExpression;
} Calculator;


int calcInit(Calculator *calc);
int calcClose(Calculator *calc);

int calcReadLine(Calculator *calc);
int calcParseLine(Calculator *calc);
float calcLineResult(Calculator *calc);
char *calcCurrentLine(Calculator *calc);

#endif 
