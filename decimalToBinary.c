#include "Conversion.h"

#define MAX 100

/*******************************************************
 * Algorithme                                          *
 * 1) Trouver la puissance de 2 la plus proche         *
 * 2) Soustraire                                       *
 *******************************************************/

char* decimalToBinary(int decimal) {

	int res = 1; /*juste pour res soit différent de 0*/
	unsigned int powerMax = 0;
	unsigned int i;
	char* binary = NULL;
	char* power = NULL;

	binary = malloc(sizeof(*binary) * (MAX + 1));
	power = malloc(sizeof(*power) * (MAX + 1));

	/*Définir la puissance de 2 à calculer */

	while (decimal > 0) {

		do {
			res = decimal - (2 << powerMax);
			powerMax++;
		} while (res > 0);
		powerMax--;

		res = 1;
		decimal -= (1 << powerMax);
		
		/*initialisation de la chaîne des puissances*/
		for (i = 0; i <= powerMax; i++) {
			power[i] = '0';
		}
		power[i-powerMax] = '1';

		i = 0;
		powerMax = 0;
	}
	



	return binary;
}

