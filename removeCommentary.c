#include "CompileFromText.h"

/*removeCommentary : permet d'enlever les commentaires d'un fichier assembleur *
 *pour la compilation.                                                         *
 * input : fichier source.txt                                                  *
 * output : source sans commentaires                                           */

/*ATTENTION : on détecte un commentaire avec "espace"+# */

FILE* removeCommentary(FILE* source) {

	FILE* sourceWithoutCom = NULL;
	int character;

	sourceWithoutCom = fopen("sourceWithoutCom.txt", "w");
	source = fopen("source.txt", "r");

	if (sourceWithoutCom == NULL) {
		fprintf(stderr, "Unable to open the file \n");
		exit(EXIT_FAILURE);
	}

	while (fgetc(source) != EOF) {
		if (fgetc(source) == ' #') {
			fputc("\n", source);
		}
		fgetc(source);
	}

	while (fgetc(source) != EOF) {
		fputc(fgetc(source), sourceWithoutCom);
	}

	return sourceWithoutCom;
	

	/* '#' en décimal d'après la table ASCII */

}