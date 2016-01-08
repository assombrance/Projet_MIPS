#include "decimalToBinary.h"

/*******************************************************
 * Algorithme                                          *
 * 1) Trouver la puissance de 2 la plus proche         *
 * 2) Soustraire                                       *
 *******************************************************/

int decimalToBinary(int decimal) {

	int res = 1; /*juste pour res soit diff�rent de 0*/
	unsigned int powerMax = 0;
	unsigned int power;

	/*D�finir la puissance de 2 � calculer */

	while (decimal > 0) {

		do {
			res = decimal - (2 << powerMax);
			powerMax++;
		} while (res > 0);

		res = 1;
		decimal -= (2 << powerMax);

	}
	

	return res;
}

