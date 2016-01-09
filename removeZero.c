#include "Conversion.h"

char* removeZero(char* binary) {

	unsigned int i = 0;
	unsigned int length;
	char* TEMP = NULL;
	unsigned int j = 0;

	TEMP = malloc(sizeof(TEMP) + 32);

	length = strlen(binary);

	/*Parcours de la chaîne jusqu'au premier 1*/
	while (binary[i] != '1') {
		i++;
	}

	/*Retournement de la chaîne de caractères*/
	for (i; i < length; i++) {
		TEMP[j] = binary[i];
		j++;
	}
	TEMP[j] = '\0';
	/*Etape non nécessaire*/
	/*
	for (i = 0; i < j; i++) {
		binary[i] = TEMP[i];
	}
	binary[i] = '\0';
	*/

	return binary;

}