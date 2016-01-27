#include "bibliotheque.h"

void convMnemoniqueEmul(char* ligne, char* memoire, int32_t* registres) {

	unsigned int i = 0;
	unsigned int j;
	unsigned int offset;
	char* operation = NULL;

	malloc(sizeof(*res) * 32);
	mask = malloc(sizeof(*res) * 32);
	operation = malloc(sizeof(*operation) * ((MAX_SIZE_MNEMO) + 1));

	/*Curseur de début d'instruction*/
	while (ligne[i] == '\t' || ligne[i] == ' ') {
		i++;
	}

	offset = i;

	for (j = offset; j <= MAX_SIZE_MNEMO + offset; j++) {
		operation[j - offset] = ligne[i];
		i++;
	}
	operation[j - 2] = '\0';

	/*Suppresion des caractères après un espace*/
	for (j = 0; j <= MAX_SIZE_MNEMO; j++) {
		if (operation[j] == ' ') {
			operation[j] = '\0';
		}
		j++;
	}

	if (operation == "add") {
		addEmul(ligne);
	}
	else if (operation == "addi") {
		addiEmul(ligne);
	}
	else if (operation == "sub") {
		subEmul(ligne);
	}
	else if (operation == "mult") {
		multEmul(ligne);
	}
	else if (operation == "div") {
		divEmul(ligne);
	}
	else if (operation == "and") {
		andEmul(ligne);
	}
	else if (operation == "or") {
		orEmul(ligne);
	}
	else if (operation == "xor") {
		xorEmul(ligne);
	}
	else if (operation == "rotr") {
		rotrEmul(ligne);
	}
	else if (operation == "sll") {
		sllEmul(ligne);
	}
	else if (operation == "srl") {
		srlEmul(ligne);
	}
	else if (operation == "slt") {
		sltEmul(ligne);
	}
	else if (operation == "lw") {
		lwEmul(ligne);
	}
	else if (operation == "sw") {
		swEmul(ligne);
	}
	else if (operation == "lui") {
		luiEmul(ligne);
	}
	else if (operation == "mfhi") {
		mfhiEmul(ligne);
	}
	else if (operation == "mflo") {
		mfloEmul(ligne);
	}
	else if (operation == "beq") {
		beqEmul(ligne);
	}
	else if (operation == "bne") {
		bneEmul(ligne);
	}
	else if (operation == "bgtz") {
		bgtzEmul(ligne);
	}
	else if (operation == "blez") {
		blezEmul(ligne);
	}
	else if (operation == "j") {
		jEmul(ligne);
	}
	else if (operation == "jal") {
		jalEmul(ligne);
	}
	else if (operation == "jr") {
		jrEmul(ligne);
	}
	else {
		fprintf(stderr, "Mnémonique non reconnue \n");
	}

	free(operation);
}