#include "Conversion.h"

/* binaryToHexa_ET : permet de faire un ET logique entre chaque terme de deux chaînes
	de caractères.                                                                   */

char* ET(char* resBinary, char* mask) {

	char* res;
	unsigned int i;

	res = malloc(sizeof(*res) * (strlen(mask) + 1));

	for (i = 0; i < strlen(mask); i++) {
		res[i] = resBinary[i] & mask[i];
	}
	res[i] = '\0';

	return res;
}