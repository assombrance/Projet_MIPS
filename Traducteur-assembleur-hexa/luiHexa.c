#include "fonctionsHexa.h"
#include "Conversion.h"

/* lui rt, immediate */

char* luiHexa(char* res, char* instruction) {
	
	unsigned int i = 0;
	int rt, imm;
	char* rt_b = NULL;
	char* imm_b = NULL;
	char* LUI = NULL;
	char* res_LUI = NULL;
	char* hexadecimal = res;


	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	rt = atoiTranslator(instruction, i); /*enregistrement de rt*/
	i++;

	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	imm = atoiTranslator(instruction, i); /*enregistrement de imm*/
	
	
	rt_b = decimalToBinary(rt_b, rt);
	imm_b = decimalToBinary(imm_b, imm);

	rt_b = normalizeLengthOfField(rt_b, ADDRESS_REGISTER);
	imm_b = normalizeLengthOfField(imm_b, IMMEDIATE);

	LUI = malloc(sizeof(*LUI) * strlen("00111100000") + 1);

	if ((LUI == NULL)) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	strcpy(LUI, "00111100000");

	res_LUI = strcatTranslator3(res_LUI, LUI, rt_b, imm_b);

	hexadecimal = binaryToHexa(hexadecimal, res_LUI);

	free(LUI);
	free(res_LUI);
	free(imm_b);
	free(rt_b);

	return hexadecimal;
}
