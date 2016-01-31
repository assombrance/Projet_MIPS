#include "Conversion.h"
#include "fonctionsHexa.h"

int countLines(FILE* source) {

	int nbOfLines = 0;
	int carac;

	if (source == NULL) {
		fprintf(stderr, "Unable to open file \n");
		exit(EXIT_FAILURE);
	}

	while (!feof(source)) {

		carac = fgetc(source);

		if (carac == '\n') {
			nbOfLines++;
		}
	}

	return nbOfLines + 1;
}