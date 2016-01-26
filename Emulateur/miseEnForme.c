#include "bibliotheque.h"

void miseEnForme(void) {

	FILE* output = NULL;
	FILE* source = NULL;
	int character;

	output = fopen("output.txt", "w");
	source = fopen("source.txt", "r");

	if ((source == NULL) || (output == NULL)) {
		fprintf(stderr, "Unable to open the file \n");
		exit(EXIT_FAILURE);
	}


	do {
		do {
			character = fgetc(source);
		} while (((char)character == ' ') || ((char)character == '\t')||(((char)character == '\n')));
		if ((char)character == '#') {
			while ((char)fgetc(source)!='\n');
		} else {
			do {
				fputc(character,output);
				character = fgetc(source);
			} while (((char)character!='\n')&&(character!=EOF));
			if ((char)character=='\n') fputc(character,output);
		}
	} while (character != EOF);
	fclose(output);
	fclose(source);
}