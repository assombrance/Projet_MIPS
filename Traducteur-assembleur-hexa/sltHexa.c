#include "fonctionsHexa.h"
#include "Conversion.h"

/* SLT rd, rs, rt */

char* sltHexa(char* res, char* instruction) {
	
	unsigned int i = 0;
	int rs, rt, rd;
	char* rs_b = NULL;
	char* rt_b = NULL;
	char* rd_b = NULL;
	char* res_SLT = NULL;
	char* SLT = NULL;
	char* special = NULL;
	char* hexadecimal = res;

	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	rd = atoiTranslator(instruction, i); /*enregistrement de rd*/
	i++;

	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}
	
	rs = atoiTranslator(instruction, i); /*enregistrement de rs (décimal)*/
	i++;
	
	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}
	
	rt = atoiTranslator(instruction, i); /*enregistrement de rt*/
	
	rs_b = decimalToBinary(rs_b, rs);
	rt_b = decimalToBinary(rt_b, rt);
	rd_b = decimalToBinary(rd_b, rd);

	rt_b = normalizeLengthOfField(rt_b, ADDRESS_REGISTER);
	rs_b = normalizeLengthOfField(rs_b, ADDRESS_REGISTER);
	rd_b = normalizeLengthOfField(rd_b, ADDRESS_REGISTER);

	special = malloc(sizeof(*special) * strlen("000000") + 1);
	SLT = malloc(sizeof(*SLT) * strlen("00000101010") + 1);

	if ((special == NULL) || (SLT == NULL)) {
		fprintf(stderr, "Unable to allocate memory !\n");
		exit(EXIT_FAILURE);
	}

	strcpy(special, "000000");
	strcpy(SLT, "00000101010");

	res_SLT = strcatTranslator5(res_SLT, special, rs_b, rt_b, rd_b, SLT);

	hexadecimal = binaryToHexa(hexadecimal, res_SLT);

	free(special);
	free(SLT);
	free(res_SLT);
	free(rs_b);
	free(rt_b);
	free(rd_b);
	
	return hexadecimal;
}