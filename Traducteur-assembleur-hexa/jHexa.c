#include "fonctionsHexa.h"
#include "Conversion.h"

/* j target */

char* jHexa(char* res, char* instruction) {
	
	unsigned int i = 0;
	int ind;
	char* ind_b = NULL;
	char* res_J = NULL;
	char* J = NULL;
	char* hexadecimal = res;

	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	ind = atoiTranslator(instruction, i); /*enregistrement de ind*/
	
	
	ind_b = decimalToBinary(ind_b, ind);

	ind_b = normalizeLengthOfField(ind_b, INSTRUCT_INDEX);

	J = malloc(sizeof(*J) * strlen("000010") + 1);

	if ((J == NULL)) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	strcpy(J, "000010");

	res_J = strcatTranslator2(res_J, J, ind_b);

	hexadecimal = binaryToHexa(hexadecimal, res_J);
	
	free(J);
	free(res_J);
	free(ind_b);

	return hexadecimal;
}