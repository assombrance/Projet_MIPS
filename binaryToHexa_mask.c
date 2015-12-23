#include "binaryToHexa.h"

/* binaryToHexa_mask : cr�ation d'un masque 
	length : taille de la chaine de caract�re
	offset : d�but de la s�rie de "1"
	nb : nombre de "1" dans le maque		*/

char* binaryToHexa_mask(length, offset, nb) {

	char *mask = NULL;
	unsigned int i;

	mask = malloc(sizeof(*mask) * (length + 1));
	
	i = 0;

	/* Cr�ation d'une cha�ne de 0 */
	while (*mask++) {
		mask[i] = '0';
		i++;
	}
	mask[i] = '\0';

	/* Ajout des "1" dans la cha�ne de "0" */
	for (i = offset; i < offset + nb; i++) {
		mask[i] = '1';
	}

	return mask;
}