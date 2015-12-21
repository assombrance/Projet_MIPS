#include "binaryToHexa.h"

#define HALF_BYTE 4

char* binaryToHexa(char* binary) {

	int length;
	int nb_HALF_BYTE;
	int i, j;
	char* resBinary;
	char* resHexa;

	/*Le compilateur fonctionne avec des blocs de 1 octet minimum*/
	resBinary = malloc(HALF_BYTE);
	resHexa = malloc(HALF_BYTE);

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
		for (i; i < (HALF_BYTE + HALF_BYTE*j) ; ++i) {
			if (binary[i] == '1') {
				resBinary[i] = '1';
			}
			else {
				resBinary[i] = '0';
			}
		}

		/* Le nombre de 0 en fin de masque importe peu*/
		if ((resBinary || "11110000") == "0000") {
			resHexa[j] = '0';
		}
		else if (resBinary || "11110000" == "0001") {
			resHexa[j] = '1';
		}
		else if (resBinary || "11110000" == "0010") {
			resHexa[j] = '2';
		}
		else if (resBinary || "11110000" == "0011") {
			resHexa[j] = '3';
		}
		else if (resBinary || "11110000" == "0100") {
			resHexa[j] = '4';
		}
		else if (resBinary || "11110000" == "0101") {
			resHexa[j] = '5';
		}
		else if (resBinary || "11110000" == "0110") {
			resHexa[j] = '6';
		}
		else if (resBinary || "11110000" == "0111") {
			resHexa[j] = '7';
		}
		else if (resBinary || "11110000" == "1000") {
			resHexa[j] = '8';
		}
		else if (resBinary || "11110000" == "1001") {
			resHexa[j] = '9';
		}
		else if (resBinary || "11110000" == "1010") {
			resHexa[j] = 'A';
		}
		else if (resBinary || "11110000" == "1011") {
			resHexa[j] = 'B';
		}
		else if (resBinary || "11110000" == "1100") {
			resHexa[j] = 'C';
		}
		else if (resBinary || "11110000" == "1101") {
			resHexa[j] = 'D';
		}
		else if (resBinary || "11110000" == "1110") {
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

	return resHexa;
}