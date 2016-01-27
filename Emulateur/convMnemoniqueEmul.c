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

	if (strcmp(operation, "add")) {
		addEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "addi")) {
		addiEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "sub")) {
		subEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "mult")) {
		multEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "div")) {
		divEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "and")) {
		andEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "or")) {
		orEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "xor")) {
		xorEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "rotr")) {
		rotrEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "sll")) {
		sllEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "srl")) {
		srlEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "slt")) {
		sltEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "lw")) {
		lwEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "sw")) {
		swEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "lui")) {
		luiEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "mfhi")) {
		mfhiEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "mflo")) {
		mfloEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "beq")) {
		beqEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "bne")) {
		bneEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "bgtz")) {
		bgtzEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "blez")) {
		blezEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "j")) {
		jEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "jal")) {
		jalEmul(ligne, memoire, registres);
	}
	else if (strcmp(operation, "jr")) {
		jrEmul(ligne, memoire, registres);
	}
	else {
		fprintf(stderr, "Mnémonique non reconnue \n");
	}

	printf("%s\n",ligne);
	addiEmul(ligne, memoire, registres);

	printf("____________________________________________________________________________________\n");
	printf("registre n° :\t1\t 2\t 3\t 4\t 5\t HI\t LO\n");
	printf("contenu :\t%d \t %d \t %d \t %d \t %d \t %d \t %d\n",registres[1],registres[2],registres[3],registres[4],registres[5],registres[34], registres[33]);
	printf("____________________________________________________________________________________\n");
	printf("mémoire :\t1\t 2\t 3\t 4\t 5\n");
	printf("\t\t%d \t %d \t %d \t %d \t %d\n", memoire[1],memoire[2],memoire[3],memoire[4],memoire[5]);
	printf("____________________________________________________________________________________\n\n");
}