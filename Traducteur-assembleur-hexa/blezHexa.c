#include "fonctionsHexa.h"
#include "Conversion.h"

/* blez rs, offset */

char* blezHexa(char* res, char* instruction) {

	unsigned int i = 0;
	int rs, off;
	char* rs_b = NULL;
	char* off_b = NULL;
	char* BLEZ = NULL;
	char* res_BLEZ = NULL;
	char* zeros = NULL;
	char* hexadecimal = res;

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
	off_b = decimalToBinary(off_b, off);

	rs_b = normalizeLengthOfField(rs_b, ADDRESS_REGISTER);
	off_b = normalizeLengthOfField(off_b, OFFSET);

	BLEZ = malloc(sizeof(*BLEZ) * strlen("000110") + 1);
	zeros = malloc(sizeof(*zeros) * strlen("00000") + 1);

	if ((BLEZ == NULL) || (zeros == NULL)) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	strcpy(BLEZ, "000110");
	strcpy(zeros, "00000");

	res_BLEZ = strcatTranslator4(res_BLEZ, BLEZ, rs_b, zeros, off_b);
	
	hexadecimal = binaryToHexa(hexadecimal, res_BLEZ);

	free(BLEZ);
	free(zeros);
	free(res_BLEZ);
	free(rs_b);
	free(off_b);
	
	return hexadecimal;
}