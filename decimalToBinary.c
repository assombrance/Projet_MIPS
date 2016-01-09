#include "Conversion.h"

/*******************************************************
 * Algorithme                                          *
 * 1) Trouver la puissance de 2 la plus proche         *
 * 2) Soustraire                                       *
 *******************************************************/

char* decimalToBinary(int decimal) {

	int decimal_absValue;
	char* binary = NULL;
	unsigned int i;
	int carry;

	binary = malloc(sizeof(*binary) + 32);

	if (decimal < 0) {
		decimal_absValue = abs(decimal);
		binary = Conversion_decimalBinary(decimal_absValue);

		/*Complément à deux*/
		/*Inversion des bits*/
		for (i = 0; i < strlen(binary); i++) {
			if (binary[i] == '0') {
				binary[i] = '1';
			}
			else {
				binary[i] = '0';
			}
		}
		binary[i] = '\0';

		/*Addition de 1*/
		if ()


	}
	else {
		binary = Conversion_decimalBinary(decimal);
	}

	binary = Conversion_normalizeLength(binary);


	return binary;
}

