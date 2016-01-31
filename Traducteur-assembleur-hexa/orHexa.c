#include "fonctionsHexa.h"
#include "Conversion.h"

/* or rd, rs, rt */

char* orHexa(char* res, char* instruction) {

	unsigned int i = 0;
	int rd, rs, rt;
	char* special = NULL;
	char* OR = NULL;
	char* rd_b = NULL;
	char* rs_b = NULL;
	char* rt_b = NULL;
	char* res_OR = NULL;
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

	rs_b = normalizeLengthOfField(rs_b, ADDRESS_REGISTER);
	rt_b = normalizeLengthOfField(rt_b, ADDRESS_REGISTER);
	rd_b = normalizeLengthOfField(rd_b, ADDRESS_REGISTER);

	OR = malloc(sizeof(*OR) * strlen("00000100101") + 1);
	special = malloc(sizeof(*special) * strlen("000000") + 1);

	if ((OR == NULL) || (special == NULL)) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	strcpy(OR, "00000100101");
	strcpy(special, "000000");

	res_OR = strcatTranslator5(res_OR, special, rs_b, rt_b, rd_b, OR);

	hexadecimal = binaryToHexa(hexadecimal, res_OR);

	free(special);
	free(OR);
	free(rd_b);
	free(rs_b);
	free(rt_b);
	free(res_OR);

	return hexadecimal;
}