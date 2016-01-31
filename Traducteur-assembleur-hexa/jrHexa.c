#include "fonctionsHexa.h"
#include "Conversion.h"

/* jr rs */

char* jrHexa(char* res, char* instruction) {
	
	unsigned int i = 0;
	int rs;
	char* JR = NULL;
	char* special = NULL;
	char* hint = NULL;
	char* zeros = NULL;
	char* rs_b = NULL;
	char* res_JR = NULL;
	char* hexadecimal = res;


	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	rs = atoiTranslator(instruction, i); /* enregistrement de rs */
	
	
	rs_b = decimalToBinary(rs_b, rs);

	rs_b = normalizeLengthOfField(rs_b, ADDRESS_REGISTER);

	JR = malloc(sizeof(*JR) * strlen("001000") + 1);
	special = malloc(sizeof(*special) * strlen("000000") + 1);
	hint = malloc(sizeof(*hint) * 5 + 1);
	zeros = malloc(sizeof(*zeros) * strlen("0000000000") + 1);


	if ( (JR == NULL) || (special == NULL) || (hint == NULL) || (zeros == NULL)) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	strcpy(JR, "001000");
	strcpy(special, "000000");
	if (RELEASE == 1) {
		strcpy(hint, "00000");
	} else {
		/* Simulation de l'encodage d'une instruction hazard barrier */
		strcpy(hint, "10000");
	}
	strcpy(zeros, "0000000000");

	res_JR = strcatTranslator5(res_JR, special, rs_b, zeros, hint, JR);

	hexadecimal = binaryToHexa(hexadecimal, res_JR);

	free(special);
	free(JR);
	free(hint);
	free(zeros);
	free(res_JR);
	free(rs_b);

	return hexadecimal;
}