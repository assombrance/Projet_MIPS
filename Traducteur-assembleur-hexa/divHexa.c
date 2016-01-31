#include "fonctionsHexa.h"
#include "Conversion.h"

/* div rs, rt */

char* divHexa(char* res, char* instruction) {
	
	unsigned int i = 0;
	int rs, rt;
	char* rs_b = NULL;
	char* rt_b = NULL;
	char* DIV = NULL;
	char* special = NULL;
	char* res_DIV = NULL;
	char* hexadecimal = res;


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

	rs_b = normalizeLengthOfField(rs_b, ADDRESS_REGISTER);
	rt_b = normalizeLengthOfField(rt_b, ADDRESS_REGISTER);

	DIV = malloc(sizeof(*DIV) * strlen("0000000000011010") + 1);
	special = malloc(sizeof(*special) * strlen("000000") + 1);

	if ((DIV == NULL) || (special == NULL)) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	strcpy(DIV, "0000000000011010");
	strcpy(special, "000000");

	res_DIV = strcatTranslator4(res_DIV, special, rs_b, rt_b, DIV);
	
	hexadecimal = binaryToHexa(hexadecimal, res_DIV);

	free(DIV);
	free(special);
	free(res_DIV);
	free(rs_b);
	free(rt_b);
	
	return hexadecimal;
}