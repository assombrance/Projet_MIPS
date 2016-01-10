#include "CompileFromText.h"

char* convMnemonique(char* ligne) {

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
	if (operation == "ADD") {
		res = addHexa(ligne);
	}
	else if (operation == "ADDI") {
		res = addiHexa(ligne);
	}
	else if (operation == "SUB") {
		res = subHexa(ligne);
	}
	else if (operation == "MULT") {
		res = multHexa(ligne);
	}
	else if (operation == "DIV") {
		res = divHexa(ligne);
	}
	else if (operation == "AND") {
		res = andHexa(ligne);
	}
	else if (operation == "OR") {
		res = orHexa(ligne);
	}
	else if (operation == "XOR") {
		res = xorHexa(ligne);
	}
	else if (operation == "ROTR") {
		res = rotrHexa(ligne);
	}
	else if (operation == "SLL") {
		res = sllHexa(ligne);
	}
	else if (operation == "SRL") {
		res = srlHexa(ligne);
	}
	else if (operation == "SLT") {
		res = sltHexa(ligne);
	}
	else if (operation == "LW") {
		res = lwHexa(ligne);
	}
	else if (operation == "SW") {
		res = swHexa(ligne);
	}
	else if (operation == "LUI") {
		res = luiHexa(ligne);
	}
	else if (operation == "MFHI") {
		res = mfhiHexa(ligne);
	}
	else if (operation == "MFLO") {
		res = mfloHexa(ligne);
	}
	else if (operation == "BEQ") {
		res = beqHexa(ligne);
	}
	else if (operation == "BNE") {
		res = bneHexa(ligne);
	}
	else if (operation == "BGTZ") {
		res = bgtzHexa(ligne);
	}
	else if (operation == "BLEZ") {
		res = blezHexa(ligne);
	}
	else if (operation == "J") {
		res = jHexa(ligne);
	}
	else if (operation == "JAL") {
		res = jalHexa(ligne);
	}
	else if (operation == "JR") {
		res = jrHexa(ligne);
	}
	else {
		fprintf(stderr, "Mnémonique non reconnue \n");
	}
	*/

	return res;

}