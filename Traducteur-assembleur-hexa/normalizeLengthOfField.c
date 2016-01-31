#include "Conversion.h"

char* normalizeLengthOfField(char* rs, int LENGTH_DEFINED) {

	char* binary_normalized = rs;

	unsigned int i = 0; 
	unsigned int length;
	int shift;

	printf("NORMALIZELENGTHOFFIELD : binary_normalized => %p (après init) \n", binary_normalized );

	length = strlen(rs);
	shift = LENGTH_DEFINED - length;

	if (length < LENGTH_DEFINED) {

		binary_normalized = realloc(rs, sizeof(*binary_normalized) * (length + shift) + 1);
		printf("NORMALIZELENGTHOFFIELD : binary_normalized => %p (après realloc) \n", binary_normalized );

		
		if (binary_normalized == NULL) {
			fprintf(stderr, "Unable to reallocate memory\n");
			exit(EXIT_FAILURE);
		}

		/* Décalage des bits de rs vers la fin de chaîne de binary_normalized */
		for (i = 0; i < length; i++) {
			binary_normalized[LENGTH_DEFINED - 1 - i] = rs[length -1 - i];
		}

		/* Bourrage par des 0 pour remplir la chaîne binary_normalized        */
		for (i = 0; i < shift; i++) {
			binary_normalized[i] = '0';
		}

		binary_normalized[LENGTH_DEFINED] = '\0';

		return binary_normalized;

	} else {
		return rs;
	}

}