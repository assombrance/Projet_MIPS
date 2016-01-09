#include "Conversion.h"

#define MAX 100

/*******************************************************
 * Algorithme                                          *
 * 1) Trouver la puissance de 2 la plus proche         *
 * 2) Soustraire                                       *
 *******************************************************/

char* decimalToBinary(int decimal) {

	int res = 1; /*juste pour res soit diff�rent de 0*/
	unsigned int maximumPower = 0;
	unsigned int i = 0;
	char* binary = NULL;
	int power[MAX];
	int TEMP;

	binary = malloc(sizeof(*binary) * (MAX + 1));
	/* power = malloc(sizeof(*power) * (MAX + 1));*/


	/*D�finir la puissance de 2 � calculer */

	while (decimal > 0) {

		while (res > 0) {
			res = decimal - (1 << maximumPower);
			maximumPower++;
		}
		maximumPower = maximumPower - 2; /*La boucle while fait 2 tours de trop... penser � revoir la condition d'arr�t*/
		decimal -= (1 << maximumPower);
		
		/*tableau regroupant les puissances de deux successives*/
		power[i] = maximumPower;

		i++;
		res = 1;
		maximumPower = 0;
	}
	power[i] = '\0';



	return binary;
}

