#include "binaryToHexa.h"

int binaryToDecimal(char* binary) {

	int length;
	int i;
	int res = 0;

	length = strlen(binary);

	/* Parcours de la chaîne de droite à gauche pour la conversion*/
		for (i = 0; i < length; i++) {
			printf("i = %d : ", i);
			if (binary[i] == '1') {
				res = (res << 1) | 1;
				printf("res = %d \n", res);
			}
			else {
				res = res << 1;
				printf("res = %d \n", res);

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
	printf("Conversion en décimal de la chaine : %d \n", res);

	return res;
}