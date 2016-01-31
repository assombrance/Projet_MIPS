#include "fonctionsHexa.h"
#include "Conversion.h"

/* jal target */

char* jalHexa(char* res, char* instruction) {
	
	int ind;
	unsigned int i = 0;
	char* ind_b = NULL;
	char* res_JAL = NULL;
	char* JAL = NULL;
	char* hexadecimal = res;
	
	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	ind = atoiTranslator(instruction, i); /*enregistrement de ind*/
	
	
	ind_b = decimalToBinary(ind_b, ind);

	ind_b = normalizeLengthOfField(ind_b, INSTRUCT_INDEX);

	JAL = malloc(sizeof(*JAL) * strlen("000011") + 1);

	if ((JAL == NULL)) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	strcpy(JAL, "000011");
	
	res_JAL = strcatTranslator2(res_JAL, JAL, ind_b);

	hexadecimal = binaryToHexa(hexadecimal, res_JAL);

	free(JAL);
	free(ind_b);
	free(res_JAL);

	return hexadecimal;
}