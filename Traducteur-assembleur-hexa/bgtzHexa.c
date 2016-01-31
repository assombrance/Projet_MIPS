#include "fonctionsHexa.h"
#include "Conversion.h"

/* bgtz rs, offset */

char* bgtzHexa(char* res, char* instruction) {
	
	int rs, off;
	unsigned int i = 0;
	char* rs_b = NULL;
	char* off_b = NULL;
	char* BGTZ = NULL;
	char* zeros = NULL;
	char* res_BGTZ = NULL;
	char* hexadecimal = res;

	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	rs = atoiTranslator(instruction, i); /*enregistrement de rs*/
	i++;
	
	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	off = atoiTranslator(instruction, i);/*enregistrement de off*/
	
	
	rs_b = decimalToBinary(rs_b, rs);
	off_b = decimalToBinary(off_b, off);

	rs_b = normalizeLengthOfField(rs_b, ADDRESS_REGISTER);
	off_b = normalizeLengthOfField(off_b, OFFSET);

	BGTZ = malloc(sizeof(*BGTZ) * strlen("000111") + 1);
	zeros = malloc(sizeof(*zeros) * strlen("00000") + 1);

	if ((BGTZ == NULL) || (zeros == NULL)) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	strcpy(BGTZ, "000111");
	strcpy(zeros, "00000");

	res_BGTZ = strcatTranslator4(res_BGTZ, BGTZ, rs_b, zeros, off_b);

	hexadecimal = binaryToHexa(hexadecimal, res_BGTZ);

	free(BGTZ);
	free(zeros);
	free(res_BGTZ);
	free(rs_b);
	free(off_b);
	
	return hexadecimal;
}