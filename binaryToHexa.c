#include "binaryToHexa.h"

#define HALF_BYTE 4

char* binaryToHexa(char* binary) {

	int length;
	int nb_HALF_BYTE;
	unsigned int i, j, k;
	char* mask;
	char* resBinary = NULL;
	char* resHexa = NULL;
	char* binary_masked = NULL;
	char* binary_parsed = NULL;

	printf("taille de la chaine à convertir en octets : %d", sizeof(binary));

	/*Le compilateur fonctionne avec des blocs de 1 octet minimum*/
	resBinary = malloc(sizeof(*resBinary) * (strlen(binary) + 1) );
	resHexa = malloc(sizeof(*resHexa) * (strlen(binary) + 1) );
	binary_parsed = malloc(sizeof(*binary_parsed) * (HALF_BYTE + 1));


	if (resBinary == NULL || resHexa == NULL) {
		fprintf(stderr, "Allocation mémoire impossible \n");
		exit(EXIT_FAILURE);
	}

	length = strlen(binary);

	if (length % HALF_BYTE == 0) {
		nb_HALF_BYTE = length / HALF_BYTE;
	}
	else {
		nb_HALF_BYTE = ceil(length / HALF_BYTE);
	}

	/* Parcours de la chaîne de droite à gauche pour la conversion*/
	i = 0;
	for (j = 0; j < nb_HALF_BYTE; j++) {


		for (i; i < (HALF_BYTE + HALF_BYTE*j); i++) {
			if (binary[i] == '1') {
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