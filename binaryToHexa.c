#include "binaryToHexa.h"

#define HALF_BYTE 4

char* binaryToHexa(char* binary) {

	unsigned int i, j, k;
	char* mask;
	char* resBinary = NULL;
	char* resHexa = NULL;
	char* binary_masked = NULL;
	char* binary_parsed = NULL;
	char* binary_normalized = NULL;

	/*Le compilateur fonctionne avec des blocs de 1 octet minimum*/
	resBinary = malloc(sizeof(*resBinary) * (strlen(binary) + 1));
	resHexa = malloc(sizeof(*resHexa) * (strlen(binary) + 1));
	binary_parsed = malloc(sizeof(*binary_parsed) * (HALF_BYTE + 1));
	binary_normalized = malloc(sizeof(*binary_normalized) * 32);

	if (resBinary == NULL || resHexa == NULL || binary_parsed == NULL || binary_normalized == NULL ) {
		fprintf(stderr, "Allocation m�moire impossible \n");
		exit(EXIT_FAILURE);
	}

	/* Normalisation de la taille de la cha�ne � convertir */
	binary_normalized = binaryToHexa_normalizeLength(binary);

	/* Parcours de la cha�ne de gauche � droite pour la conversion*/
	i = 0;

	for (j = 0; j < strlen(binary_normalized) / HALF_BYTE; j++) {

		for (i; i < (HALF_BYTE + HALF_BYTE*j); i++) {
			if (binary_normalized[i] == '1') {
				resBinary[i] = '1';
			}
			else {
				resBinary[i] = '0';
			}
		}
		resBinary[i] = '\0';

		mask = binaryToHexa_mask(strlen(resBinary), i + 1 - 4, 4);
		binary_masked = malloc(sizeof(*binary_masked) * (strlen(mask) + 1));
		for (k = 0; k < strlen(mask); k++) {
			binary_masked[k] = '0';
		}
		binary_masked[k] = '\0';
		binary_masked = binaryToHexa_ET(resBinary, mask);
		binary_parsed = binaryToHexa_parsing(binary_masked);

		resHexa[j] = binaryToHexa_conversion(binary_parsed);
		resHexa[j + 1] = '\0';

		/* 'b' pour indiquer que la valeur que l'on renseigne est binaire */

		/*
		while (binary[i] != 'b' && i <= length) {
		i++;
		}

		printf("Valeur de i : %d\n", i );
		*/

	}

	return resHexa;
}