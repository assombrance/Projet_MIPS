#include "Conversion.h"

/* Inverse les bits d'une chaîne binaire */

char* invertBits(char* binary) {

	/* Libère la mémoire de la variable binary à la fin */

	/* Inversion des bits pour préparer le complément à deux */
	char* res = NULL;
	unsigned int i;

	res = malloc(sizeof(*res) * strlen(binary) + 1);

	for (i = 0; i < strlen(binary); i++) {
		if (binary[i] == '1') {
			res[i] = '0';
		} else {
			res[i] = '1';
		}
	}
	res[i] = '\0';

	free(binary);

	return res;
}