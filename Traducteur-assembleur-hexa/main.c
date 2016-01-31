#include "fonctionsHexa.h"
#include "Conversion.h"

int main(int argc, char* argv[]) {

	FILE* source = NULL;
	FILE* sourceForLines = NULL;
	FILE* sourceForCarac = NULL;
	FILE* output = NULL;
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int length_buffer = 0;
	int nbOfLines;
	int nbOfCaracMax = 30;
	int flag;
	char* ligne = NULL;
	char* res = NULL;
	char* mnemonic = NULL;

	source = fopen("source.txt", "r");
	sourceForLines = fopen("source.txt", "r");
	sourceForCarac = fopen("source.txt", "r");
	output = fopen("output.txt", "w");

	ligne = malloc(sizeof(*ligne) * 100 + 1);
	
	if (source == NULL) {
		fprintf(stderr, "Unable to open one of the file \n");
		exit(EXIT_FAILURE);
	}
	
	/* Compter le nombre de lignes du fichier source */
	nbOfLines = countLines(sourceForLines);
	printf("NUmber of lines : %d \n", nbOfLines ); 
	fclose(sourceForLines);
		
	res = malloc(sizeof(*res) * (x86 / HALF_BYTE) + 1);
	mnemonic = malloc(sizeof(*mnemonic) * 5 + 1);

	while ( i <= nbOfLines) {
		
		printf("nbOfCaracMax = %d \n", nbOfCaracMax );

		fgets(ligne, nbOfCaracMax, source);

		for (j =0 ; j < strlen(ligne); j++) {
			if (ligne[j] == '\0') {
				length_buffer = j;
			}
		}

		ligne = realloc(ligne, sizeof(*ligne) * length_buffer + 1);

		printf("MAIN : ligne => %p (après realloc) \n", ligne);
		stringTest(ligne);
		printf("Passage à convMnemonic ...\n");

		res = convMnemonic(res, mnemonic, ligne);

		stringTest(res);

		flag = fputs(res, output);
		fprintf(output, "\n");
		
		if (flag == EOF) {
			fprintf(stderr, "Write failure occured \n");
			exit(EXIT_FAILURE);
		}

		getchar();

		/* while((currentCarac = fgetc(source)) != '\n' && currentCarac != EOF);*/

		i++;

	}
		/*Filtrer la mnémonique présente dans la ligne */
	
	fclose(source);
	fclose(sourceForCarac);
	fclose(output);
	free(ligne);
	free(res);
	free(mnemonic);
	

	return 0;
}
