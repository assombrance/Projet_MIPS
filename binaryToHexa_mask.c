#include "binaryToHexa.h"

/* binaryToHexa_mask : création d'un masque 
	length : taille de la chaine de caractère
	offset : début de la série de "1"
	nb : nombre de "1" dans le maque		*/

char* binaryToHexa_mask(length, offset, nb) {

	char* mask;
	unsigned int i;

	mask = malloc(length);
	
	i = 0;

	while (mask[i] != EOF) {
		mask[i] = '0';
		i++;
	}

	for (i = offset; i <= offset + nb; i++) {
		mask[i] = '1';
	}

	return mask;
}