#include "fonctionsHexa.h"
#include "Conversion.h"

/* mfhi rd */

char* mfhiHexa(char* res, char* instruction) {

	unsigned int i = 0;
	int rd; 
	char* rd_b = NULL;
	char* MFHI = NULL;
	char* special = NULL;
	char* res_MFHI = NULL;
	char* hexadecimal = res;

	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	rd = atoiTranslator(instruction, i); /*enregistrement de rd*/
		
	rd_b = decimalToBinary(rd_b, rd);

	rd_b = normalizeLengthOfField(rd_b, ADDRESS_REGISTER);

	MFHI = malloc(sizeof(*MFHI) * strlen("00000010000") + 1);
	special = malloc(sizeof(*special) * strlen("0000000000000000") + 1);

	if ((MFHI == NULL) || (special == NULL)) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	strcpy(MFHI, "00000010000");
	strcpy(special, "0000000000000000");

	res_MFHI = strcatTranslator3(res_MFHI, special, rd_b, MFHI);

	hexadecimal = binaryToHexa(hexadecimal, res_MFHI);

	free(special);
	free(MFHI);
	free(res_MFHI);
	free(rd_b);
	
	return hexadecimal;
}
