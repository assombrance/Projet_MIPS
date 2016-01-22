#include "Conversion.h"

/* binaryToHexa_mask : cr�ation d'un masque 
	length : nombre de bits de masque
	offset : bit de d�but de la s�rie de "1", offset � [1;length]
	nb : nombre de "1" dans le masque		*/

char* Cmask(length, offset, nb) {

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
		for (i = offset - 1; i < (offset - 1) + nb; i++) {
			mask[i] = '1';
	
		}
	
	return mask;
}