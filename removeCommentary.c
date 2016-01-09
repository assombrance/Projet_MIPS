#include "compileFromText.h"

/*removeCommentary : permet d'enlever les commentaires d'un fichier assembleur *
 *pour la compilation.                                                         *
 * input : fichier source.txt                                                  *
 * output : source sans commentaires                                           */

FILE* removeCommentary(FILE* source) {

	FILE* sourceWithoutCom = NULL;
	int character;

	sourceWithoutCom = fopen(source, "r");

	if (sourceWithoutCom == NULL) {
		fprintf(stderr, "Unable to open the file \n");
		exit(EXIT_FAILURE);
	}

	do {
		character = fgetc(source);
	} while (character != 35);

	/* '#' en décimal d'après la table ASCII */

}