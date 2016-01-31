#include "fonctionsHexa.h"
#include "Conversion.h"

/* LW rt, offset(base) */

char* lwHexa(char* res, char* instruction) {
	
	unsigned int i = 0;
	int rt, off, base;
	char* rt_b = NULL;
	char* off_b = NULL;
	char* LW = NULL;
	char* res_LW = NULL;
	char* base_b = NULL;
	char* hexadecimal = res;

	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	rt = atoiTranslator(instruction, i); /*enregistrement de rt*/
	i++;

	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}
	
	off = atoiTranslator(instruction, i); /*enregistrement de off*/
	i++;
	
	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	base = atoiTranslator(instruction, i); /*enregistrement de base*/
	
	rt_b = decimalToBinary(rt_b, rt);
	off_b = decimalToBinary(off_b, off);
	base_b = decimalToBinary(base_b, base);


	rt_b = normalizeLengthOfField(rt_b, ADDRESS_REGISTER);
	off_b = normalizeLengthOfField(off_b, OFFSET);
	base_b = normalizeLengthOfField(base_b, BASE);


	LW = malloc(sizeof(*LW) * strlen("100011") + 1);

	if ((LW == NULL)) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	strcpy(LW, "100011");

	res_LW = strcatTranslator4(res_LW, LW, base_b, rt_b, off_b);
	
	hexadecimal = binaryToHexa(hexadecimal, res_LW);

	free(LW);
	free(res_LW);
	free(rt_b);
	free(off_b);
	free(base_b);

	return hexadecimal;
}