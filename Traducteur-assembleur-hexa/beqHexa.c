#include "fonctionsHexa.h"
#include "Conversion.h"

/* beq rs, rt, offset */

char* beqHexa(char* res, char* instruction) {
	
	int rs,rt,off;
	unsigned int i = 0;
	char* rs_b = NULL;
	char* rt_b = NULL;
	char* off_b = NULL;
	char* BEQ = NULL;
	char* res_BEQ = NULL;
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

	BEQ = malloc(sizeof(*BEQ) * strlen("000100") + 1);

	if ((BEQ == NULL)) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	strcpy(BEQ, "000100");

	res_BEQ = strcatTranslator4(res_BEQ, BEQ, rs_b, rt_b, off_b);

	hexadecimal = binaryToHexa(hexadecimal, res_BEQ);

	free(BEQ);
	free(rs_b);
	free(rt_b);
	free(off_b);
	free(res_BEQ);

	return hexadecimal;
}