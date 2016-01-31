#include "fonctionsHexa.h"
#include "Conversion.h"

/* mult rs, rt */

char* multHexa(char* res, char* instruction) {
	
	unsigned int i = 0;
	int rs, rt;
	char* rs_b = NULL;
	char* rt_b = NULL;
	char* MULT = NULL;
	char* res_MULT = NULL;
	char* special = NULL;
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

	MULT = malloc(sizeof(*MULT) * strlen("0000000000011000") + 1);
	special = malloc(sizeof(*special) * strlen("000000") + 1);

	if ((MULT == NULL) || (special == NULL) ) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	strcpy(MULT, "0000000000011000");
	strcpy(special, "000000");

	res_MULT = strcatTranslator4(res_MULT, special, rs_b, rt_b, MULT);

	hexadecimal = binaryToHexa(hexadecimal, res_MULT);

	free(special);
	free(MULT);
	free(rs_b);
	free(rt_b);
	free(res_MULT);

	return hexadecimal;
}