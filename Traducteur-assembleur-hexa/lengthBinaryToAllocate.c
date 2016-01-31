#include "Conversion.h"

/***********************************************/
/*      lengthBinaryToAllocate                 */
/***********************************************/

/* Permet de calculer la taille de chaîne dynami-
   que à allouer pour un entier donné          */


int lengthBinaryToAllocate(int decimal) {

 /* Renvoi la taille de la chaîne en bits à allouer pour le décimal
	exple : lengthBinaryToAllocate(512) = 10        */

	unsigned int lengthToAllocate = 0;
	int residue = 1;
	int TEMP;

	if (decimal < 0) {
		TEMP = abs(decimal);
	} else if (decimal == 0 || decimal == 1) {
		return 1;
	} else {
		TEMP = decimal;
	}

	while (residue > 0) {
		residue = TEMP - (1 << lengthToAllocate);
		lengthToAllocate++;
	}

	return lengthToAllocate;
}