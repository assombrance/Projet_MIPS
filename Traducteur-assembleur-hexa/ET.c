#include "Conversion.h"

/*************************************************************************************/
/*                            ET                                                     */
/*************************************************************************************/

/* Permet d'appliquer le masque à une chaîne de bits                                 */

char* ET(char* res, char* binaryToApplyMask, char* mask) {

	/* Malloc de la taille de la chaine mask */
	unsigned int i;

	for (i = 0; i < strlen(mask); i++) {
		res[i] = binaryToApplyMask[i] & mask[i];
	}
	res[i] = '\0';

	return res;
}