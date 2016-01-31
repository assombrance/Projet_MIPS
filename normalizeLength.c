#include "Conversion.h"

#define HALF_BYTE 4

/*binaryToHexa_normalizeLength : binaryToHexa v1.1 ne fonctionne qu'avec des chaînes
binaires dont la taille est un multiple de 4.
Le but de cette méthode est de généraliser binaryToHexa à toutes les tailles de
chaîne.
input : chaîne de caractère à normaliser										*/

char* normalizeLength(char* binary) {

	unsigned int length;
	unsigned int r, offset;
	unsigned int i, j;
	char* binary_normalized = NULL;

	length = strlen(binary);
	r = length % HALF_BYTE;
	offset = HALF_BYTE - r;

	if (r != 0) {

		binary_normalized = malloc(sizeof(*binary_normalized) * (length + offset + 1));

		for (i = offset; i <= length + offset; i++) {
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