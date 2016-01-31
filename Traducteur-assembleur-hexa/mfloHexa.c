#include "fonctionsHexa.h"
#include "Conversion.h"

/* mflo rd */

char* mfloHexa(char* res, char* instruction) {

	unsigned int i = 0;
	int rd;
	char* rd_b = NULL;
	char* res_MFLO = NULL;
	char* special = NULL;
	char* MFLO = NULL;
	char* hexadecimal = res;

	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	rd = atoiTranslator(instruction, i); /*enregistrement de rd*/
	
	rd_b = decimalToBinary(rd_b, rd);

	rd_b = normalizeLengthOfField(rd_b, ADDRESS_REGISTER);

	MFLO = malloc(sizeof(*MFLO) * strlen("00000010010") + 1);
	special = malloc(sizeof(*special) * strlen("0000000000000000") + 1);

	if ((MFLO == NULL) || (special == NULL)) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	strcpy(MFLO, "00000010010");
	strcpy(special, "0000000000000000");

	res_MFLO = strcatTranslator3(res_MFLO, special, rd_b, MFLO);

	hexadecimal = binaryToHexa(hexadecimal, res_MFLO);

	free(special);
	free(MFLO);
	free(res_MFLO);
	free(rd_b);
	
	return hexadecimal;
}
