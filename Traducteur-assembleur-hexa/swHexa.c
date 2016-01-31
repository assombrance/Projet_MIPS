#include "fonctionsHexa.h"
#include "Conversion.h"

/* SW rt, offset(base) */

char* swHexa(char* res, char* instruction) {
	
	unsigned int i = 0;
	int rt, off, base;
	char* rt_b = NULL;
	char* off_b = NULL;
	char* SW = NULL;
	char* res_SW = NULL;
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


	SW = malloc(sizeof(*SW) * strlen("101011") + 1);

	if ((SW == NULL)) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	strcpy(SW, "101011");

	res_SW = strcatTranslator4(res_SW, SW, base_b, rt_b, off_b);
	
	hexadecimal = binaryToHexa(hexadecimal, res_SW);

	free(SW);
	free(res_SW);
	free(rt_b);
	free(off_b);
	free(base_b);

	return hexadecimal;
}