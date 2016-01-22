//#include "CompileFromText.h"
#include "bibliotheque.h"
#include <string.h> // à enlever plus tard

int main(int argc, char* argv[]) {

	/*FILE* source = NULL;
	int currentCarac = 0;
	unsigned int i = 0;
	unsigned int j = 0;
	char* BUFFER = NULL;
	char* res = NULL;*/
	char* memoire = NULL;
	int32_t* registres = NULL; // registre spéciaux : 33->LO ; 34->HI
	char* instruction_test = NULL;

	//source = fopen("source.txt", "r");

	instruction_test = malloc(sizeof(*instruction_test)*50);
	registres = malloc(sizeof(*registres) * 35);
	memoire = malloc(sizeof(*memoire) * 1024);
	//BUFFER = malloc(sizeof(*BUFFER) * 32);
	//res = malloc(sizeof(*BUFFER) * 32);

	registres[1]=1;
	registres[2]=2;
	registres[3]=3;
	
	memoire[2]=17;
	memoire[3]=4;

	printf("%d \t %d \t %d \t %d \t %d\n%d \t %d \t %d\n\n",registres[1],registres[2],registres[3],registres[33], registres[34],memoire[1],memoire[2],memoire[3]);
	//getchar();

	strcpy(instruction_test, "addi 2, 3, 123");

	addiEmul(instruction_test, memoire, registres);

	printf("%d \t %d \t %d \t %d \t %d\n%d \t %d \t %d\n\n",registres[1],registres[2],registres[3],registres[33], registres[34],memoire[1],memoire[2],memoire[3]);
	
	/*if (source == NULL) {
		fprintf(stderr, "Unable to open one of the file \n");
		exit(EXIT_FAILURE);
	}*/
	
	
		/*Lecture ligne par ligne et écriture dans une chaine de caractères*/
		/*	# : 35
			tabulation : 9
			espace : 32
		*/
	
	/*for (j = 0; j <= 100; j++) {
		do {
			currentCarac = fgetc(source);
			printf("%d", currentCarac);
			BUFFER[i] = currentCarac;
			i++;
		} while (currentCarac != '\n');

		BUFFER[i] = '\0';

		res = convMnemonique(BUFFER, memoire, registres);
	
		BUFFER = malloc(sizeof(*BUFFER) * 32);
		i = 0;
	}*/
		/*Filtrer la mnémonique présente dans la ligne */
	
	//fclose(source);


	return 0;
}