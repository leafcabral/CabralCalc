#include <stdio.h>
#include <string.h>

#include "calculator.h"

int main(void) {
	Calculator calc;
	calcInit(&calc);

	puts("Type \'quit\' to close program.");
	do {
		printf(">> ");
		calcReadLine(&calc);
		
		calcParseLine(&calc)
		float result = calcLineResult(&calc);

		printf("%f\n", result);
	} while (strcmp(calcCurrentLine(&calc), 'quit'));

	calcClose(&calc);
	return 0;
}

