#include <stdio.h>

#include "calculator.h"

int main(void) {
	Calculator calc;
	calcInit(&calc);

	puts("Type \'$\' to close program.");
	do {
		printf(">> ");
		calcReadLine(&calc);
		
		calcParseLine(&calc)
		float result = calcLineResult(&calc);

		printf("%f\n", result);
	} while (calcCurrentLine(&calc)[0] != '$');

	calcClose(&calc);
	return 0;
};
