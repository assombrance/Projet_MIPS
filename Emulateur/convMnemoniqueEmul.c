#include "bibliotheque.h"

void convMnemoniqueEmul(char* ligne, char* memoire, int32_t* registres) {

	unsigned int i = 0, j = 0;
	char operation[5];

	/*Curseur de début d'instruction*/
	while (ligne[i] == '\t' || ligne[i] == ' ') {
		i++;
	}

	while (ligne[i] != '\t' && ligne[i] != ' ') {
		operation[j] = ligne[i];
		i++; j++;
	}
	operation[j] = '\0';

	if (strcmp(operation, "add") == 0 ) {
		addEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "addi") == 0 ) {
		addiEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "sub") == 0 ) {
		subEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "mult") == 0 ) {
		multEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "div") == 0 ) {
		divEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "and") == 0 ) {
		andEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "or") == 0 ) {
		orEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "xor") == 0 ) {
		xorEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "rotr") == 0 ) {
		rotrEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "sll") == 0 ) {
		sllEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "srl") == 0 ) {
		srlEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "slt") == 0 ) {
		sltEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "lw") == 0 ) {
		lwEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "sw") == 0 ) {
		swEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "lui") == 0 ) {
		luiEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "mfhi") == 0 ) {
		mfhiEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "mflo") == 0 ) {
		mfloEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "beq") == 0 ) {
		beqEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "bne") == 0 ) {
		bneEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "bgtz") == 0 ) {
		bgtzEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "blez") == 0 ) {
		blezEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "j") == 0 ) {
		jEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "jal") == 0 ) {
		jalEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "jr") == 0 ) {
		jrEmul(ligne, memoire, registres);
	}
	else {
		fprintf(stderr, "Mnémonique non reconnue \n");
	}

	printf("%s\n",ligne);

	if (pasAPas);
		printf("____________________________________________________________________________________\n");
		printf("registre n° :\t1\t 2\t 3\t 4\t 5\t HI\t LO\t PC\n");
		printf("contenu :\t%d \t %d \t %d \t %d \t %d \t %d \t %d\t %d\n",registres[1],registres[2],registres[3],registres[4],registres[5], registres[34], registres[33],registres[32]);
		printf("____________________________________________________________________________________\n");
		printf("mémoire :\t1\t 2\t 3\t 4\t 5\n");
		printf("\t\t%d \t %d \t %d \t %d \t %d\n", memoire[1],memoire[2],memoire[3],memoire[4],memoire[5]);
		printf("____________________________________________________________________________________\n\n");
		getchar();
	}
}