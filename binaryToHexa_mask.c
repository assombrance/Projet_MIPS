#include "binaryToHexa.h"

/* binaryToHexa_mask : cr�ation d'un masque 
	length : nombre de bits de masque
	offset : bit de d�but de la s�rie de "1", offset � [1;length]
	nb : nombre de "1" dans le masque		*/

char* binaryToHexa_mask(length, offset, nb) {

	char *mask;
	unsigned int i;

	mask = malloc(sizeof(*mask) * (length + 1));
	
	i = 0;

	/* Cr�ation d'une cha�ne de 0 */
	while (i < length) {
		mask[i] = '0';
		i++;
	}
	mask[i] = '\0';

	/* Ajout des "1" dans la cha�ne de "0" */
	if (offset + nb <= strlen(mask)) {
		for (i = offset - 1; i < (offset - 1) + nb; i++) {
			mask[i] = '1';
		}
	}
	else {
		fprintf(stderr, "Le nombre de bits � 1 exc�de la taille du masque \n");
		exit(EXIT_FAILURE);
	}
	
	return mask;
}