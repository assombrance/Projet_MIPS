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

char* decimalToBinary(char* binary_returned, int decimal) {

	char* binary = binary_returned;

	if (decimal > 0) {
		binary = decimalBinary(binary, decimal);
	} 
	else {
		binary = decimalBinary(binary, decimal);
		binary = invertBits(binary);
		binary = addOneToBinary(binary);
	}

	return binary;
}