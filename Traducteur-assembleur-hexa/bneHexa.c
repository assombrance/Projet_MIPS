#include "fonctionsHexa.h"
#include "Conversion.h"

/* bne rs, rt, offset */

char* bneHexa(char* res, char* instruction) {
	
	unsigned int i = 0;
	int rs, rt, off;
	char* rs_b = NULL;
	char* rt_b = NULL;
	char* off_b = NULL;
	char* BNE = NULL;
	char* res_BNE = NULL;
	char* hexadecimal = res;


	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	rt = atoiTranslator(instruction, i); /*enregistrement de rt*/
	i++;
	
	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	rs = atoiTranslator(instruction, i); /*enregistrement de rs*/
	i++;
	
	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	off = atoiTranslator(instruction, i); /*enregistrement de off*/
	

	rs_b = decimalToBinary(rs_b, rs);
	rt_b = decimalToBinary(rt_b, rt);
	off_b = decimalToBinary(off_b, off);

	rs_b = normalizeLengthOfField(rs_b, ADDRESS_REGISTER);
	rt_b = normalizeLengthOfField(rt_b, ADDRESS_REGISTER);
	off_b = normalizeLengthOfField(off_b, OFFSET);

	BNE = malloc(sizeof(*BNE) * strlen("000101") + 1);

	if ((BNE == NULL)) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	strcpy(BNE, "000101");

	res_BNE = strcatTranslator4(res_BNE, BNE, rs_b, rt_b, off_b);

	hexadecimal = binaryToHexa(hexadecimal, res_BNE);

	free(BNE);
	free(res_BNE);
	free(rs_b);
	free(rt_b);
	free(off_b);
	
	return hexadecimal;
}