#include "Conversion.h"

char* decimalBinary(int decimal) {

	unsigned int i;
	char* binary = NULL;
	int power = SIZE_MAX;
	int res = 0;
	int decimal_absValue;

	binary = malloc(sizeof(*binary) + 32);

	/*
	if (decimal < 0) {
	fprintf(stderr," \n ************decimalToBinary_v2.0************* \n Sorry, this version does not work with negativ numbers \n Our developpers are on it. \n Thanks for your patience. \n");
	exit(EXIT_FAILURE);
	}
	*/

	/*Ne fonctionne pas avec des nombres négatifs*/
	for (i = 0; i <= SIZE_MAX; i++) {

		res = decimal - (1 << power);

		if (res >= 0) {
			binary[i] = '1';
			decimal = res;
		}
		else {
			binary[i] = '0';
			res = decimal;
		}

		power--;
	}

	binary[i] = '\0';

	return binary;
}