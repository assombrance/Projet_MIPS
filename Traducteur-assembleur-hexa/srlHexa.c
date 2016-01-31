#include "fonctionsHexa.h"
#include "Conversion.h"

/* SRL rt, rd, sa */

char* srlHexa(char* res, char* instruction) {

	unsigned int i = 0;
	int sa, rt, rd;
	char* sa_b = NULL;
	char* rt_b = NULL;
	char* rd_b = NULL;
	char* res_SRL = NULL;
	char* SRL = NULL;
	char* special = NULL;
	char* hexadecimal = res;

	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	rd = atoiTranslator(instruction, i); /*enregistrement de rd*/
	i++;

	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}
	
	sa = atoiTranslator(instruction, i); /*enregistrement de sa (décimal)*/
	i++;
	
	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}
	
	rt = atoiTranslator(instruction, i); /*enregistrement de rt*/

	sa_b = decimalToBinary(sa_b, sa);
	rt_b = decimalToBinary(rt_b, rt);
	rd_b = decimalToBinary(rd_b, rd);

	rt_b = normalizeLengthOfField(rt_b, ADDRESS_REGISTER);
	sa_b = normalizeLengthOfField(sa_b, ADDRESS_REGISTER);
	rd_b = normalizeLengthOfField(rd_b, ADDRESS_REGISTER);

	special = malloc(sizeof(*special) * strlen("00000000000") + 1);
	SRL = malloc(sizeof(*SRL) * strlen("000010") + 1);

	if ((special == NULL) || (SRL == NULL)) {
		fprintf(stderr, "Unable to allocate memory !\n");
		exit(EXIT_FAILURE);
	}

	strcpy(special, "00000000000");
	strcpy(SRL, "000010");

	res_SRL = strcatTranslator5(res_SRL, special, rt_b, rd_b, sa_b, SRL);

	hexadecimal = binaryToHexa(hexadecimal, res_SRL);

	free(special);
	free(SRL);
	free(res_SRL);
	free(sa_b);
	free(rt_b);
	free(rd_b);
	
	return hexadecimal;
}