#include "Conversion.h"

char* removeZero(char* binary) {

	unsigned int i = 0;
	unsigned int length;
	char* TEMP = NULL;
	unsigned int j = 0;

	TEMP = malloc(sizeof(TEMP) + 32);

	length = strlen(binary);

	/*Parcours de la cha�ne jusqu'au premier 1*/
	while (binary[i] != '1') {
		i++;
	}

	/*Retournement de la cha�ne de caract�res*/
	for (i; i < length; i++) {
		TEMP[j] = binary[i];
		j++;
	}
	TEMP[j] = '\0';
	/*Etape non n�cessaire*/
	/*
	for (i = 0; i < j; i++) {
		binary[i] = TEMP[i];
	}
	binary[i] = '\0';
	*/

	return binary;

}