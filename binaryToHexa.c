#include "binaryToHexa.h"

#define HALF_BYTE 4

char* binaryToHexa(char* binary) {

	int length;
	int nb_HALF_BYTE;
	int i, j;
	char* resBinary;
	char* resHexa;

	resBinary = malloc(sizeof(binary));
	resHexa = malloc(sizeof(binary));

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
	for (j = 0; j < nb_HALF_BYTE; j++) {
		for (i = 0; i < HALF_BYTE; i++) {
			if (binary[i] == '1') {
				resBinary[i] = '1';
			}
			else {
				resBinary[i] = '0';
			}
		}

		if (resBinary == "0000") {
			resHexa[j] = '0';
		}
		else if (resBinary == "0001") {
			resHexa[j] = '1';
		}
		else if (resBinary == "0010") {
			resHexa[j] = '2';
		}
		else if (resBinary == "0011") {
			resHexa[j] = '3';
		}
		else if (resBinary == "0100") {
			resHexa[j] = '4';
		}
		else if (resBinary == "0101") {
			resHexa[j] = '5';
		}
		else if (resBinary == "0110") {
			resHexa[j] = '6';
		}
		else if (resBinary == "0111") {
			resHexa[j] = '7';
		}
		else if (resBinary == "1000") {
			resHexa[j] = '8';
		}
		else if (resBinary == "1001") {
			resHexa[j] = '9';
		}
		else if (resBinary == "1010") {
			resHexa[j] = 'A';
		}
		else if (resBinary == "1011") {
			resHexa[j] = 'B';
		}
		else if (resBinary == "1100") {
			resHexa[j] = 'C';
		}
		else if (resBinary == "1101") {
			resHexa[j] = 'D';
		}
		else if (resBinary == "1110") {
			resHexa[j] = 'E';
		}
		else {
			resHexa[j] = 'F';
		}
	}
	

	/* 'b' pour indiquer que la valeur que l'on renseigne est binaire */

	/*
	while (binary[i] != 'b' && i <= length) {
	i++;
	}

	printf("Valeur de i : %d\n", i );
	*/
	printf("Taille de la chaine à convertir : %d \n", length);
	//printf("Conversion en décimal de la chaine : %d \n", res);

	free(resBinary);
	free(resHexa);

	return resHexa;
}