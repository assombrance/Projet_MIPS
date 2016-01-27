#include "bibliotheque.h"
#include <string.h> // à enlever plus tard

int main(int argc, char* argv[]) {

	char* memoire = NULL;
	int32_t* registres = NULL; // registre spéciaux : 32->PC le Programm counter ; 33->LO (les bits de poids faible); 34->HI (les bits de poids fort)
	char* BUFFER = NULL;
	int tailleSource = 0, position = 0; //en lignes
	int character, i;
	FILE* source = NULL;

	registres = malloc(sizeof(*registres) * 35);
	memoire = malloc(sizeof(*memoire) * 1024);
	BUFFER = malloc(sizeof(BUFFER) * 32);
	registres[32]=0;

	miseEnForme("source.txt", "sourceNormalisee.txt");
	tailleSource = taille("sourceNormalisee.txt");
	
	do {
		source = fopen("sourceNormalisee", "r");

		do { // on va à la bonne position
			character = fgetc(source);
			if ((char)character == '\n') position++;
		} while ((position != registres[32]/4) && (character != EOF));
		
		do {//on recopie la ligne dans BUFFER
			character = fgetc(source);
			BUFFER[i] = character;
			i++;
		} while ((character != '\n') && (character != EOF));
		BUFFER[i] = '\0';
		convMnemoniqueEmul(BUFFER);
		i = 0;
		registres[32]+=4; //une instruction fait 4 octets

		if ( registres[32] > tailleSource*4 ) {
			fprintf(stderr, "PC en dehors de la source\n");
			exit(EXIT_FAILURE);
		}

		fclose(source);
		position = 0;
	} while (character != EOF)

	return 0;
}


















/*
 affichage du fonctionnement de addi (exemple)

 	char* instruction_test = NULL;

	instruction_test = malloc(sizeof(*instruction_test)*50);

	registres[1]=1;
	registres[2]=2;
	registres[3]=3;

	memoire[1]=82;

	printf("____________________________________________________________________________________\n");
	printf("registre n° :\t1\t 2\t 3\t 4\t 5\t HI\t LO\n");
	printf("contenu :\t%d \t %d \t %d \t %d \t %d \t %d \t %d\n",registres[1],registres[2],registres[3],registres[4],registres[5],registres[34], registres[33]);
	printf("____________________________________________________________________________________\n");
	printf("mémoire :\t1\t 2\t 3\t 4\t 5\n");
	printf("\t\t%d \t %d \t %d \t %d \t %d\n", memoire[1],memoire[2],memoire[3],memoire[4],memoire[5]);
	printf("____________________________________________________________________________________\n\n");
	
	strcpy(instruction_test, "addi 2, 3, 123");
	printf("%s\n",instruction_test);
	addiEmul(instruction_test, memoire, registres);

	printf("____________________________________________________________________________________\n");
	printf("registre n° :\t1\t 2\t 3\t 4\t 5\t HI\t LO\n");
	printf("contenu :\t%d \t %d \t %d \t %d \t %d \t %d \t %d\n",registres[1],registres[2],registres[3],registres[4],registres[5],registres[34], registres[33]);
	printf("____________________________________________________________________________________\n");
	printf("mémoire :\t1\t 2\t 3\t 4\t 5\n");
	printf("\t\t%d \t %d \t %d \t %d \t %d\n", memoire[1],memoire[2],memoire[3],memoire[4],memoire[5]);
	printf("____________________________________________________________________________________\n\n");
*/