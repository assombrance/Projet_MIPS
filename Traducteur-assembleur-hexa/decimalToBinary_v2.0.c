#include "Conversion.h"

/************************************/
/*     decimalToBinary_v3.0         */
/************************************/

/* Permet de convertir un entier rela-
   tif en chaîne binaire.
   La taille de la chaîne binaire ren-
   due est minimale.

   Bug : Supprimer le 0 en début de 
   chaîne sur conversion d'entiers  */

char* decimalToBinary(int decimal) {

	char* res = NULL;

	if (decimal > 0) {
		res = decimalBinary(decimal);
	} 
	else {
		res = decimalBinary(decimal);
		res = invertBits(res);
		res = addOneToBinary(res);
	}

	return res;
}