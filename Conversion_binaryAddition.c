#include "Conversion.h"

char* Conversion_binaryAddition(char* binary_1, char* binary_2) {

	unsigned int i;
	unsigned int length_1, length_2;
	unsigned int length;
	char* res;

	res = malloc(sizeof(*res) + 32);

	length_1 = strlen(binary_1);
	length_2 = strlen(binary_2);
	/*
	if (length_1 - length_2 > 0) {
		binary_2 = Conversion_equalizingLength(binary_1, binary_2);
	}
	*/

	length = strlen(binary_1);

	for (i = 0; i < length; i++) {

	}


}