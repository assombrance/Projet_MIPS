//#include "CompileFromText.h"
#include "bibliotheque.h"
#include <string.h> // à enlever plus tard

int main(int argc, char* argv[]) {

	char* memoire = NULL;
	int32_t* registres = NULL; // registre spéciaux : 33->LO ; 34->HI
	char* instruction_test = NULL;

	instruction_test = malloc(sizeof(*instruction_test)*50);
	registres = malloc(sizeof(*registres) * 35);
	memoire = malloc(sizeof(*memoire) * 1024);

	registres[1]=1;
	registres[2]=2;
	registres[3]=3;

	memoire[1]=82;

	printf("____________________________________________________________________________________\n");
	printf("registre n° :\t1\t 2\t 3\t 4\t 5\t LO\t HI\n");
	printf("contenu :\t%d \t %d \t %d \t %d \t %d \t %d \t %d\n",registres[1],registres[2],registres[3],registres[4],registres[5],registres[33], registres[34]);
	printf("____________________________________________________________________________________\n");
	printf("mémoire :\t1\t 2\t 3\t 4\t 5\n");
	printf("\t\t%d \t %d \t %d \t %d \t %d\n", memoire[1],memoire[2],memoire[3],memoire[4],memoire[5]);
	printf("____________________________________________________________________________________\n\n");
	
	strcpy(instruction_test, "addi 2, 3, 123");
	printf("%s\n",instruction_test);
	addiEmul(instruction_test, memoire, registres);

	printf("____________________________________________________________________________________\n");
	printf("registre n° :\t1\t 2\t 3\t 4\t 5\t LO\t HI\n");
	printf("contenu :\t%d \t %d \t %d \t %d \t %d \t %d \t %d\n",registres[1],registres[2],registres[3],registres[4],registres[5],registres[33], registres[34]);
	printf("____________________________________________________________________________________\n");
	printf("mémoire :\t1\t 2\t 3\t 4\t 5\n");
	printf("\t\t%d \t %d \t %d \t %d \t %d\n", memoire[1],memoire[2],memoire[3],memoire[4],memoire[5]);
	printf("____________________________________________________________________________________\n\n");

	strcpy(instruction_test, "add 4, 3, 1");
	printf("%s\n",instruction_test);
	addEmul(instruction_test, memoire, registres);

	printf("____________________________________________________________________________________\n");
	printf("registre n° :\t1\t 2\t 3\t 4\t 5\t LO\t HI\n");
	printf("contenu :\t%d \t %d \t %d \t %d \t %d \t %d \t %d\n",registres[1],registres[2],registres[3],registres[4],registres[5],registres[33], registres[34]);
	printf("____________________________________________________________________________________\n");
	printf("mémoire :\t1\t 2\t 3\t 4\t 5\n");
	printf("\t\t%d \t %d \t %d \t %d \t %d\n", memoire[1],memoire[2],memoire[3],memoire[4],memoire[5]);
	printf("____________________________________________________________________________________\n\n");

	strcpy(instruction_test, "lw 5, 1");
	printf("%s\n",instruction_test);
	lwEmul(instruction_test, memoire, registres);

	printf("____________________________________________________________________________________\n");
	printf("registre n° :\t1\t 2\t 3\t 4\t 5\t LO\t HI\n");
	printf("contenu :\t%d \t %d \t %d \t %d \t %d \t %d \t %d\n",registres[1],registres[2],registres[3],registres[4],registres[5],registres[33], registres[34]);
	printf("____________________________________________________________________________________\n");
	printf("mémoire :\t1\t 2\t 3\t 4\t 5\n");
	printf("\t\t%d \t %d \t %d \t %d \t %d\n", memoire[1],memoire[2],memoire[3],memoire[4],memoire[5]);
	printf("____________________________________________________________________________________\n\n");

	strcpy(instruction_test, "sw 2, 2");
	printf("%s\n",instruction_test);
	swEmul(instruction_test, memoire, registres);

	printf("____________________________________________________________________________________\n");
	printf("registre n° :\t1\t 2\t 3\t 4\t 5\t LO\t HI\n");
	printf("contenu :\t%d \t %d \t %d \t %d \t %d \t %d \t %d\n",registres[1],registres[2],registres[3],registres[4],registres[5],registres[33], registres[34]);
	printf("____________________________________________________________________________________\n");
	printf("mémoire :\t1\t 2\t 3\t 4\t 5\n");
	printf("\t\t%d \t %d \t %d \t %d \t %d\n", memoire[1],memoire[2],memoire[3],memoire[4],memoire[5]);
	printf("____________________________________________________________________________________\n\n");
/*
	strcpy(instruction_test, "add 2, 3, 1");
	printf("%s\n",instruction_test);
	addiEmul(instruction_test, memoire, registres);

	printf("____________________________________________________________________________________\n");
	printf("registre n° :\t1\t 2\t 3\t 4\t 5\t LO\t HI\n");
	printf("contenu :\t%d \t %d \t %d \t %d \t %d \t %d \t %d\n",registres[1],registres[2],registres[3],registres[4],registres[5],registres[33], registres[34]);
	printf("____________________________________________________________________________________\n");
	printf("mémoire :\t1\t 2\t 3\t 4\t 5\n");
	printf("\t\t%d \t %d \t %d \t %d \t %d\n", memoire[1],memoire[2],memoire[3],memoire[4],memoire[5]);
	printf("____________________________________________________________________________________\n\n");

	strcpy(instruction_test, "add 2, 3, 1");
	printf("%s\n",instruction_test);
	addiEmul(instruction_test, memoire, registres);

	printf("____________________________________________________________________________________\n");
	printf("registre n° :\t1\t 2\t 3\t 4\t 5\t LO\t HI\n");
	printf("contenu :\t%d \t %d \t %d \t %d \t %d \t %d \t %d\n",registres[1],registres[2],registres[3],registres[4],registres[5],registres[33], registres[34]);
	printf("____________________________________________________________________________________\n");
	printf("mémoire :\t1\t 2\t 3\t 4\t 5\n");
	printf("\t\t%d \t %d \t %d \t %d \t %d\n", memoire[1],memoire[2],memoire[3],memoire[4],memoire[5]);
	printf("____________________________________________________________________________________\n\n");

	strcpy(instruction_test, "add 2, 3, 1");
	printf("%s\n",instruction_test);
	addiEmul(instruction_test, memoire, registres);

	printf("____________________________________________________________________________________\n");
	printf("registre n° :\t1\t 2\t 3\t 4\t 5\t LO\t HI\n");
	printf("contenu :\t%d \t %d \t %d \t %d \t %d \t %d \t %d\n",registres[1],registres[2],registres[3],registres[4],registres[5],registres[33], registres[34]);
	printf("____________________________________________________________________________________\n");
	printf("mémoire :\t1\t 2\t 3\t 4\t 5\n");
	printf("\t\t%d \t %d \t %d \t %d \t %d\n", memoire[1],memoire[2],memoire[3],memoire[4],memoire[5]);
	printf("____________________________________________________________________________________\n\n");

	strcpy(instruction_test, "add 2, 3, 1");
	printf("%s\n",instruction_test);
	addiEmul(instruction_test, memoire, registres);

	printf("____________________________________________________________________________________\n");
	printf("registre n° :\t1\t 2\t 3\t 4\t 5\t LO\t HI\n");
	printf("contenu :\t%d \t %d \t %d \t %d \t %d \t %d \t %d\n",registres[1],registres[2],registres[3],registres[4],registres[5],registres[33], registres[34]);
	printf("____________________________________________________________________________________\n");
	printf("mémoire :\t1\t 2\t 3\t 4\t 5\n");
	printf("\t\t%d \t %d \t %d \t %d \t %d\n", memoire[1],memoire[2],memoire[3],memoire[4],memoire[5]);
	printf("____________________________________________________________________________________\n\n");

	strcpy(instruction_test, "add 2, 3, 1");
	printf("%s\n",instruction_test);
	addiEmul(instruction_test, memoire, registres);

	printf("____________________________________________________________________________________\n");
	printf("registre n° :\t1\t 2\t 3\t 4\t 5\t LO\t HI\n");
	printf("contenu :\t%d \t %d \t %d \t %d \t %d \t %d \t %d\n",registres[1],registres[2],registres[3],registres[4],registres[5],registres[33], registres[34]);
	printf("____________________________________________________________________________________\n");
	printf("mémoire :\t1\t 2\t 3\t 4\t 5\n");
	printf("\t\t%d \t %d \t %d \t %d \t %d\n", memoire[1],memoire[2],memoire[3],memoire[4],memoire[5]);
	printf("____________________________________________________________________________________\n\n");

	strcpy(instruction_test, "add 2, 3, 1");
	printf("%s\n",instruction_test);
	addiEmul(instruction_test, memoire, registres);

	printf("____________________________________________________________________________________\n");
	printf("registre n° :\t1\t 2\t 3\t 4\t 5\t LO\t HI\n");
	printf("contenu :\t%d \t %d \t %d \t %d \t %d \t %d \t %d\n",registres[1],registres[2],registres[3],registres[4],registres[5],registres[33], registres[34]);
	printf("____________________________________________________________________________________\n");
	printf("mémoire :\t1\t 2\t 3\t 4\t 5\n");
	printf("\t\t%d \t %d \t %d \t %d \t %d\n", memoire[1],memoire[2],memoire[3],memoire[4],memoire[5]);
	printf("____________________________________________________________________________________\n\n");
*/
	return 0;
}