#include "binaryToHexa.h"

/* binaryToHexa_mask : création d'un masque 
	length : nombre de bits de masque
	offset : bit de début de la série de "1", offset € [1;length]
	nb : nombre de "1" dans le masque		*/

char* binaryToHexa_mask(length, offset, nb) {

	char *mask;
	unsigned int i;

	mask = malloc(sizeof(*mask) * (length + 1));
	
	i = 0;

	/* Création d'une chaîne de 0 */
	while (i < length) {
		mask[i] = '0';
		i++;
	}
	mask[i] = '\0';

	/* Ajout des "1" dans la chaîne de "0" */
	if (offset + nb <= strlen(mask)) {
		for (i = offset - 1; i < (offset - 1) + nb; i++) {
			mask[i] = '1';
		}
	}
	else {
		fprintf(stderr, "Le nombre de bits à 1 excède la taille du masque \n");
		exit(EXIT_FAILURE);
	}
	
	return mask;
}