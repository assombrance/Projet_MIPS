#include "bibliotheque.h"

int taille (char* nomSource){

	FILE* source = NULL;
	int character, compteur = 0;

	source = fopen(nomSource, "r");

	if (source == NULL) {
		fprintf(stderr, "Unable to open the file in taille\n");
		exit(EXIT_FAILURE);
	}

	do {
		character = fgetc(source);
		if ((char)character == '\n') compteur++;
	} while (character != EOF);
	compteur++;

	fclose(source);
	return compteur;
}