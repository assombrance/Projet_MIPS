#include "fonctionsHexa.h"
#include "Conversion.h"

/* and rd, rs, rt */

char* andHexa(char* res, char* instruction) {

	unsigned int i = 0;
	int rs,rt,rd;
	char* rs_b = NULL;
	char* rt_b = NULL;
	char* rd_b = NULL;
	char* AND = NULL;
	char* special = NULL;
	char* res_AND = NULL;
	char* hexadecimal = res;


	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	rd = atoiTranslator(instruction, i); /*enregistrement de rd*/
	i++;

	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	rs = atoiTranslator(instruction, i); /*enregistrement de rs*/
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

	special = malloc(sizeof(*special) * strlen("000000") + 1);
	AND = malloc(sizeof(*AND) * strlen("00000100100") + 1);


	if ((AND == NULL) || (special == NULL)) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	strcpy(AND, "00000100100");
	strcpy(special, "000000");

	res_AND = strcatTranslator5(res_AND, special, rs_b, rt_b, rd_b, AND);
	hexadecimal = binaryToHexa(hexadecimal, res_AND);

	free(AND);
	free(special);
	free(rs_b);
	free(rt_b);
	free(rd_b);
	free(res_AND);
	
	return hexadecimal;
}