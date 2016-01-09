#include "Conversion.h"

/*Taille de la plus grande instruction 26 bits, soit 2^25*/
#define SIZE_MAX 10 

/*******************************************************
 * Algorithme                                          *
 * 1) Trouver la puissance de 2 la plus proche         *
 * 2) Soustraire                                       *
 *******************************************************/

char* decimalToBinary(int decimal) {

	unsigned int i;
	char* binary = NULL;
	int power = SIZE_MAX;
	int res = 0;

	binary = malloc(sizeof(*binary) + 32);

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

	binary = Conversion_normalizeLength(binary);

	return binary;
}

