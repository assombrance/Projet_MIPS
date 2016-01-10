#include "compileFromText.h"

void tokenizingSource(FILE* source) {

	/*Toujours initialiser les pointeurs*/
	FILE* buffer = NULL;
	int result_closingFile;
	int carac;

	buffer = fopen(source, "r");

	if (buffer == NULL) {
		fprintf(stderr, "Unable to open the file \n");
		exit(EXIT_FAILURE);
	}

	/*Afficher le fichier .txt*/
	do {
		carac = fgetc(buffer);
		printf("%c", carac);
	} while (carac != EOF);

	/*Toujours fermer le fichier pour libérer la mémoire vive*/
	result_closingFile = fclose(buffer);

	if (result_closingFile == EOF) {
		fprintf(stderr, "Unable to close the file \n");
		exit(EXIT_FAILURE);
	}
}