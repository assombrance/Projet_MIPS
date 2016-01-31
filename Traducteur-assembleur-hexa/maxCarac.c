#include "Conversion.h"
#include "fonctionsHexa.h"

/* Renvoie le nombre de caractère maximal d'une ligne pour fputs */

int maxCarac(FILE* source) {

	unsigned int max = 0;
	int carac;

	if (source == NULL) {
		fprintf(stderr, "Unable to open the file ...\n");
		exit(EXIT_FAILURE);
	}

	while (!feof(source)) {

		carac = fgetc(source);

		if (carac != '\n') {
			max++;
		} else {
			return max + 1;
		}
		printf("max = %d \n", max );
	}

	return max + 1;
}