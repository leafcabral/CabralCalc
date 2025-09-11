#ifndef CABRAL_CALCULATOR_H
#define CABRAL_CALCULATOR_H

#define NUM_VARIABLES 9
#define NUM_HISTORY 16

typedef struct {
	union {
		struct { float A, B, C, D, E, F, M, X, Y; };
		float var[NUM_VARIABLES];
	} mem;
	
	char *buffers[NUM_HISTORY];
} Calculator;


int calcInit(Calculator *calc);
int calcReadLine(Calculator *calc);
int calcClose(Calculator *calc);

#endif 
