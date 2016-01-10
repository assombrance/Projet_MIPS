#include "compileFromText.h"

char* convMnemonique(char* ligne) {

	unsigned int i = 0;
	char* operation[MAX_SIZE_MNEMO];
	char* res = NULL;

	res = malloc(sizeof(*res) * 32);


	if (operation == "\tADD") {
		res = addHexa(ligne);
	}
	else if (operation == "\tADDI") {
		res = addiHexa(ligne);
	}
	else if (operation == "\tSUB") {
		res = subHexa(ligne);
	}
	else if (operation == "\tMULT") {
		res = multHexa(ligne);
	}
	else if (operation == "\tDIV") {
		res = divHexa(ligne);
	}
	else if (operation == "\tAND") {
		res = andHexa(ligne);
	}
	else if (operation == "\tOR") {
		res = orHexa(ligne);
	}
	else if (operation == "\tXOR") {
		res = xorHexa(ligne);
	}
	else if (operation == "\tROTR") {
		res = rotrHexa(ligne);
	}
	else if (operation == "\tSLL") {
		res = sllHexa(ligne);
	}
	else if (operation == "\tSRL") {
		res = srlHexa(ligne);
	}
	else if (operation == "\tSLT") {
		res = sltHexa(ligne);
	}
	else if (operation == "\tLW") {
		res = lwHexa(ligne);
	}
	else if (operation == "\tSW") {
		res = swHexa(ligne);
	}
	else if (operation == "\tLUI") {
		res = luiHexa(ligne);
	}
	else if (operation == "\tMFHI") {
		res = mfhiHexa(ligne);
	}
	else if (operation == "\tMFLO") {
		res = mfloHexa(ligne);
	}
	else if (operation == "\tBEQ") {
		res = beqHexa(ligne);
	}
	else if (operation == "\tBNE") {
		res = bneHexa(ligne);
	}
	else if (operation == "\tBGTZ") {
		res = bgtzHexa(ligne);
	}
	else if (operation == "\tBLEZ") {
		res = blezHexa(ligne);
	}
	else if (operation == "\tJ") {
		res = jHexa(ligne);
	}
	else if (operation == "\tJAL") {
		res = jalHexa(ligne);
	}
	else if (operation == "\tJR") {
		res = jrHexa(ligne);
	}
	else {
		fprintf(stderr, "Mnémonique non reconnue \n");
	}

	return res;

}