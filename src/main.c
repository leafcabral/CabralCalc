#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/utils.h"
#include "../include/calculator.h"


int main(void) {
	Calculator calc;
	calcInit(&calc);

	do {
		printf(">> ");
		calcReadLine(&calc);
		puts(calc.buffers[0]);
	} while (calc.buffers[0][0] != '$');

	calcClose(&calc);
	return 0;
};
