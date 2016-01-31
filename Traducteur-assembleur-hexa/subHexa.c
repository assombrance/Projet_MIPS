#include "fonctionsHexa.h"
#include "Conversion.h"

/* SUB rd, rs, rt */

char* subHexa(char* res, char* instruction) {
		
	unsigned int i = 0;
	int rs, rt, rd;
	char* rs_b = NULL;
	char* rt_b = NULL;
	char* rd_b = NULL;
	char* res_SUB = NULL;
	char* SUB = NULL;
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
	SUB = malloc(sizeof(*SUB) * strlen("00000100010") + 1);

	if ((special == NULL) || (SUB == NULL)) {
		fprintf(stderr, "Unable to allocate memory !\n");
		exit(EXIT_FAILURE);
	}

	strcpy(special, "000000");
	strcpy(SUB, "00000100010");

	res_SUB = strcatTranslator5(res_SUB, special, rs_b, rt_b, rd_b, SUB);

	hexadecimal = binaryToHexa(hexadecimal, res_SUB);

	free(special);
	free(SUB);
	free(res_SUB);
	free(rt_b);
	free(rs_b);
	free(rd_b);
	
	return hexadecimal;
}