#include "binaryToHexa.h"

#define HALF_BYTE 4

/* ***************************************************** *
 *                binaryToHexa v1.2                      *
 * Conversion d'une chaîne de caractères binaires en     *
 * héxadécimal.                                          *
 * ***************************************************** */


char* binaryToHexa(char* binary) {

	unsigned int i, j, k;
	char* mask;
	char* resBinary = NULL;
	char* resHexa = NULL;
	char* binary_masked = NULL;
	char* binary_parsed = NULL;
	char* binary_normalized = NULL;

	resBinary = malloc(sizeof(*resBinary) * (strlen(binary) + 1));
	resHexa = malloc(sizeof(*resHexa) * (strlen(binary) + 1));
	binary_parsed = malloc(sizeof(*binary_parsed) * (HALF_BYTE + 1));
	binary_normalized = malloc(sizeof(*binary_normalized) * 32);

	if (resBinary == NULL || resHexa == NULL || binary_parsed == NULL || binary_normalized == NULL ) {
		fprintf(stderr, "Allocation mémoire impossible \n");
		exit(EXIT_FAILURE);
	}

	/* Normalisation de la taille de la chaîne à convertir */
	binary_normalized = normalizeLength(binary);

	/* Parcours de la chaîne de gauche à droite pour la conversion*/
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

		/* Création du masque */
		mask = Cmask(strlen(resBinary), i + 1 - 4, 4);
		binary_masked = malloc(sizeof(*binary_masked) * (strlen(mask) + 1));
		for (k = 0; k < strlen(mask); k++) {
			binary_masked[k] = '0';
		}
		binary_masked[k] = '\0';
		/* Application du masque à la chaîne de caractères */
		binary_masked = ET(resBinary, mask);
		/* Reconnaissance des groupes de bits masqués */
		binary_parsed = parsing(binary_masked);

		resHexa[j] = binaryHexa(binary_parsed);
		resHexa[j + 1] = '\0';

	}

	return resHexa;
}