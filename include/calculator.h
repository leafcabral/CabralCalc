#ifndef CABRAL_CALCULATOR_H
#define CABRAL_CALCULATOR_H

#define CALC_NUM_HISTORY 32

typedef struct {
	char *buffers[NUM_HISTORY];

	MathExpression currentExpression;
} Calculator;


int calcInit(Calculator *calc);
int calcClose(Calculator *calc);

int calcReadLine(Calculator *calc);
int calcParseLine(Calculator *calc);
float calcLineResult(Calculator *calc);
char *calcCurrentLine(Calculator *calc);

#endif 
