#include "binaryToHexa.h"

/* binaryToHexa_mask : création d'un masque 
	length : taille de la chaine de caractère
	offset : début de la série de "1"
	nb : nombre de "1" dans le maque		*/

char* binaryToHexa_mask(length, offset, nb) {

	char *mask = NULL;
	unsigned int i;

	mask = malloc(sizeof(*mask) * (length + 1));
	
	i = 0;

	/* Création d'une chaîne de 0 */
	while (*mask++) {
		mask[i] = '0';
		i++;
	}
	mask[i] = '\0';

	/* Ajout des "1" dans la chaîne de "0" */
	for (i = offset; i < offset + nb; i++) {
		mask[i] = '1';
	}

	return mask;
}