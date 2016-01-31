#include "Conversion.h"

/*************************************************************************************/
/*                                cMask                                              */
/*************************************************************************************/

/* Permet de générer un masque de bits pour pouvoir convertir chaque groupe de 4 bits
	par son équivalent hexadécimal                                                   */
	
char* cMask(char* mask, unsigned int length_StringToBeMasked, int offset, int nbOfOnes) {

	unsigned int i;

	/* Dans le malloc on rajoute 1 pour le caractère de fin de chaîne 
	mask = malloc(sizeof(*mask) * (length_StringToBeMasked + 1));
	*/
	i = 0;

	/* Création d'une chaîne de 0 */
	while (i < length_StringToBeMasked) {
		mask[i] = '0';
		i++;
	}
	mask[i] = '\0';

	/* Ajout des "1" dans la chaîne de "0" */
	for (i = offset - 1; i < (offset - 1) + nbOfOnes; i++) {
		mask[i] = '1';

	}

	return mask;
}