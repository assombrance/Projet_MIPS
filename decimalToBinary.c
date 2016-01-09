#include "Conversion.h"

/*******************************************************
 * Algorithme                                          *
 * 1) Trouver la puissance de 2 la plus proche         *
 * 2) Soustraire                                       *
 *******************************************************/

char* decimalToBinary(int decimal) {

	int decimal_absValue;
	char* binary = NULL;
	char* binary_withoutZero = NULL;
	unsigned int i;
	int carry;

	binary = malloc(sizeof(*binary) + 32);
	binary_withoutZero = malloc(sizeof(*binary_withoutZero) + 32);

	if (decimal < 0) {
		decimal_absValue = abs(decimal);
		binary = decimalBinary(decimal_absValue);
		binary_withoutZero = removeZero(binary);

		/*Complément à deux*/
		/*Inversion des bits*/
		for (i = 0; i < strlen(binary_withoutZero); i++) {
			if (binary_withoutZero[i] == '0') {
				binary_withoutZero[i] = '1';
			}
			else {
				binary_withoutZero[i] = '0';
			}
		}
		binary_withoutZero[i] = '\0';

		/*Addition de 1*/
		binary = binaryAddition(binary_withoutZero);


	}
	else {
		binary = decimalBinary(decimal);
	}

	binary = normalizeLength(binary);


	return binary;
}

