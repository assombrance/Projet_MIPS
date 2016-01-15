#include "bibliotheques.h"

char* convMnemonique(char* ligne,char *memoire,int32_t *registres) {

	unsigned int i = 0;
	unsigned int j;
	unsigned int offset;
	char* operation = NULL;
	char* mask = NULL;
	char* res = NULL;
	char* ligne_masked = NULL;

	res = malloc(sizeof(*res) * 32);
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

	free(operation);

	/*
	if (operation == "add") {
		res = addHexa(ligne, *memoire, *registres);
	}
	else if (operation == "addi") {
		res = addiHexa(ligne, *memoire, *registres);
	}
	else if (operation == "sub") {
		res = subHexa(ligne, *memoire, *registres);
	}
	else if (operation == "mult") {
		res = multHexa(ligne, *memoire, *registres);
	}
	else if (operation == "div") {
		res = divHexa(ligne, *memoire, *registres);
	}
	else if (operation == "and") {
		res = andHexa(ligne, *memoire, *registres);
	}
	else if (operation == "or") {
		res = orHexa(ligne, *memoire, *registres);
	}
	else if (operation == "xor") {
		res = xorHexa(ligne, *memoire, *registres);
	}
	else if (operation == "rotr") {
		res = rotrHexa(ligne, *memoire, *registres);
	}
	else if (operation == "sll") {
		res = sllHexa(ligne, *memoire, *registres);
	}
	else if (operation == "srl") {
		res = srlHexa(ligne, *memoire, *registres);
	}
	else if (operation == "slt") {
		res = sltHexa(ligne, *memoire, *registres);
	}
	else if (operation == "lw") {
		res = lwHexa(ligne, *memoire, *registres);
	}
	else if (operation == "sw") {
		res = swHexa(ligne, *memoire, *registres);
	}
	else if (operation == "lui") {
		res = luiHexa(ligne, *memoire, *registres);
	}
	else if (operation == "mfhi") {
		res = mfhiHexa(ligne, *memoire, *registres);
	}
	else if (operation == "mflo") {
		res = mfloHexa(ligne, *memoire, *registres);
	}
	else if (operation == "beq") {
		res = beqHexa(ligne, *memoire, *registres);
	}
	else if (operation == "bne") {
		res = bneHexa(ligne, *memoire, *registres);
	}
	else if (operation == "bgtz") {
		res = bgtzHexa(ligne, *memoire, *registres);
	}
	else if (operation == "blez") {
		res = blezHexa(ligne, *memoire, *registres);
	}
	else if (operation == "j") {
		res = jHexa(ligne, *memoire, *registres);
	}
	else if (operation == "jal") {
		res = jalHexa(ligne, *memoire, *registres);
	}
	else if (operation == "jr") {
		res = jrHexa(ligne, *memoire, *registres);
	}
	else {
		fprintf(stderr, "Mnémonique non reconnue \n");
	}
	*/
	return res;

}