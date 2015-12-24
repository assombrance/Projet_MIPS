#include "binaryToHexa.h"

#define HALF_BYTE 4

char* binaryToHexa(char* binary) {

	int length;
	int nb_HALF_BYTE;
	unsigned int i, j;
	char* mask;
	char* resBinary = NULL;
	char* resHexa = NULL;

	printf("taille de la chaine � convertir en octets : %d", sizeof(binary));

	/*Le compilateur fonctionne avec des blocs de 1 octet minimum*/
	resBinary = malloc(sizeof(*resBinary) * (strlen(binary) + 1) );
	resHexa = malloc(sizeof(*resHexa) * (strlen(binary) + 1) );

	if (resBinary == NULL || resHexa == NULL) {
		fprintf(stderr, "Allocation m�moire impossible \n");
		exit(EXIT_FAILURE);
	}

	length = strlen(binary);

	if (length % HALF_BYTE == 0) {
		nb_HALF_BYTE = length / HALF_BYTE;
	}
	else {
		nb_HALF_BYTE = ceil(length / HALF_BYTE);
	}

	/* Parcours de la cha�ne de droite � gauche pour la conversion*/
	i = 0;
	for (j = 0; j < nb_HALF_BYTE; j++) {
		

		for (i; i < (HALF_BYTE + HALF_BYTE*j) ; i++) {
			if (binary[i] == '1') {
				resBinary[i] = '1';
			}
			else {
				resBinary[i] = '0';
			}
		}
		resBinary[i] = '\0';

		mask = binaryToHexa_mask(strlen(resBinary), i+1-4, 4);

		/* Le nombre de 0 en fin de masque importe peu*/
		if ((resBinary && mask) == "0000") {
			resHexa[j] = '0';
		}
		else if (resBinary && mask == "0001") {
			resHexa[j] = '1';
		}
		else if (resBinary && mask == "0010") {
			resHexa[j] = '2';
		}
		else if (resBinary && mask == "0011") {
			resHexa[j] = '3';
		}
		else if (resBinary && mask == "0100") {
			resHexa[j] = '4';
		}
		else if (resBinary && mask == "0101") {
			resHexa[j] = '5';
		}
		else if (resBinary && mask == "0110") {
			resHexa[j] = '6';
		}
		else if (resBinary && mask == "0111") {
			resHexa[j] = '7';
		}
		else if (resBinary && mask == "1000") {
			resHexa[j] = '8';
		}
		else if (resBinary && mask == "1001") {
			resHexa[j] = '9';
		}
		else if (resBinary && mask == "1010") {
			resHexa[j] = 'A';
		}
		else if (resBinary && mask == "1011") {
			resHexa[j] = 'B';
		}
		else if (resBinary && mask == "1100") {
			resHexa[j] = 'C';
		}
		else if (resBinary && mask == "1101") {
			resHexa[j] = 'D';
		}
		else if (resBinary && mask == "1110") {
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
	printf("Taille de la chaine � convertir : %d \n", length);

	//printf("Conversion en d�cimal de la chaine : %d \n", res);

	return resHexa;
}