#include "Conversion.h"

int atoiTranslator(char* instruction, int i) {

	/* Convertit instruction[i] en entier */
	unsigned signe;
	int j;
	int res = -1;

	if (instruction[i] == '-') {
		signe = -1;
	} else {
		signe = 1;
	}

	/* Saute le signe de l'opérande */
	if (instruction[i] == '+' || instruction[i] == '-') {
		i++;
	}

	/* isdigit(c) fonction de ctype.h retourne une valeur non nulle si c est un 
	chiffre, nulle sinon */
	for (j = 0; isdigit(instruction[i]); i++) {
		j = 10 * j + (instruction[i] - '0');
	}

	res = signe * j;

	return res;
}