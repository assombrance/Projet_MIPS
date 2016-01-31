#include "Conversion.h"
#include "fonctionsHexa.h"

/* Lit des opérandes numériques */

char* readOperand(char* instruction) {

	char* res = NULL;
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned length = 0;

	/* Passage de la mnémonique */
	while (!isdigit(instruction[i])) {
		i++;
		printf("%d\n", i );
	}

	/* Calcul de la taille de l'opérande */
	while (isdigit(instruction[i])) {
		length++;
		i++;
	}

	res = malloc(sizeof(*res) * length + 1);

	while( instruction[i] != ' ') {
		res[j] = instruction[i - length];
		j++;
	}

	res[j + 1] = '\0';


	return res;
}