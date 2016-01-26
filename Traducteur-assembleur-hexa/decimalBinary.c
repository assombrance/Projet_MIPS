#include "Conversion.h"

/************************************************/
/*     decimalBinary                            */
/************************************************/

/* Permet d'effectuer une simple conversion d'un 
   entier relatif en une chaîne binaire         */
   
char* decimalBinary(int decimal) {

	/* Conversion d'un chiffre décimal en chaîne binaire
		ATTENTION : ne fonctionne pas avec des nombres négatifs */

	char* res = NULL;
	int lengthBinaryAllocated;
	unsigned int power;
	/* Problème avec les "int" compris entre -511 et 512 */
	int residue;

	lengthBinaryAllocated = lengthBinaryToAllocate(decimal);

	if (decimal < 0) {
		/* On rajoute 1 case pour le 0 en début de chaîne */
		res = malloc(sizeof(*res) * lengthBinaryAllocated + 1 + 1);
	} else {
		res = malloc(sizeof(*res) * lengthBinaryAllocated + 1);
	}

	if (res == NULL) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	power = lengthBinaryAllocated;

	if (decimal < 0) {
		res[0] = '0';
		printf("res[0] = %c \n", res[0] );
		while (power != 0) {
		residue = abs(decimal) - (1 << (power - 1));
	
			if (residue >= 0) {
				printf("res[%d] = %c \n", lengthBinaryAllocated - power, res[lengthBinaryAllocated - power] );
				res[lengthBinaryAllocated - (power - 1)] = '1';
				decimal = residue;
			} else {
				printf("res[%d] = %c \n", lengthBinaryAllocated - power, res[lengthBinaryAllocated - power] );
				res[lengthBinaryAllocated - (power - 1)] = '0';
			}

		power--;
		}

	res[lengthBinaryAllocated - (power - 1)] = '\0';
	printf("res[%d] = %c \n", lengthBinaryAllocated - power, res[lengthBinaryAllocated - power] );


	} else {
		while (power != 0) {

		residue = decimal - (1 << (power - 1));
	
			if (residue >= 0) {
				res[lengthBinaryAllocated - power] = '1';
				decimal = residue;
			} else {
				res[lengthBinaryAllocated - power] = '0';
			}

		power--;
		}

	res[lengthBinaryAllocated - power] = '\0';	
	}
	
	
	return res;
}