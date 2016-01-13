#include "CompileFromText.h"
#include "Conversion.h"

int main(int argc, char* argv[]) {

	FILE* source = NULL;
	int currentCarac = 0;
	unsigned int i = 0;
	unsigned int j = 0;
	char* BUFFER = NULL;
	char* res = NULL;

	source = fopen("source.txt", "r");

	BUFFER = malloc(sizeof(BUFFER) * 32);
	res = malloc(sizeof(*BUFFER) * 32);

	if (source == NULL) {
		fprintf(stderr, "Unable to open one of the file \n");
		exit(EXIT_FAILURE);
	}
	
	
		/*Lecture ligne par ligne et écriture dans une chaine de caractères*/
		/*	# : 35
			tabulation : 9
			espace : 32
		*/
	
	for (j = 0; j <= 100; j++) {
		do {
			currentCarac = fgetc(source);
			printf("%d", currentCarac);
			BUFFER[i] = currentCarac;
			i++;
		} while (currentCarac != '\n');

		BUFFER[i] = '\0';

		res = convMnemonique(BUFFER);
	
		BUFFER = malloc(sizeof(*BUFFER) * 32);
		i = 0;
	}
		/*Filtrer la mnémonique présente dans la ligne */
	
	fclose(source);


	return 0;
}