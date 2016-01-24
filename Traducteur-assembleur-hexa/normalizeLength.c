#include "Conversion.h"

/************************************************************************************/
/*                            normalizeLength                                       */
/************************************************************************************/

/* Permet de normaliser la taille d'un nombre binaire pour que celle-ci soit un      
	multiple de 4                                                                   */

char* normalizeLength(char* binary_normalized, char* binary) {

	unsigned int length;
	unsigned int r, offset;
	unsigned int i, j;

	length = strlen(binary);
	r = length % HALF_BYTE;
	offset = HALF_BYTE - r;

	if (r != 0) {
		/*
		binary_normalized = malloc(sizeof(*binary_normalized) * SIZE_MAX); (length + offset + 1));*/

		for (i = offset; i < length + offset; i++) {
			binary_normalized[i] = binary[i - offset];
		}
		binary_normalized[i] = '\0';

		for (j = 0; j < offset; j++) {
			binary_normalized[j] = '0';
		}

	}
	else {
		return binary;
	}
	
	return binary_normalized;
}