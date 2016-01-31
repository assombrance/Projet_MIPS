#include "fonctionsHexa.h"
#include "Conversion.h"

/* SLL rd, rt, sa */

char* sllHexa(char* res, char* instruction) {
	
	unsigned int i = 0;
	int rd, rt, sa;
	char* rd_b = NULL;
	char* rt_b = NULL;
	char* sa_b = NULL;
	char* SLL = NULL;
	char* special = NULL;
	char* res_SLL = NULL;
	char* hexadecimal = res;


	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	rd = atoiTranslator(instruction, i); /*enregistrement de rd*/
	i++;

	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	rt = atoiTranslator(instruction, i); /*enregistrement de rt (décimal)*/
	i++;
	
	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}
	
	sa = atoiTranslator(instruction, i); /*enregistrement de sa*/	
	
	rt_b = decimalToBinary(rt_b, rt);
	sa_b = decimalToBinary(sa_b, sa);
	rd_b = decimalToBinary(rd_b, rd);

	rt_b = normalizeLengthOfField(rt_b, ADDRESS_REGISTER);
	sa_b = normalizeLengthOfField(sa_b, ADDRESS_REGISTER);
	rd_b = normalizeLengthOfField(rd_b, ADDRESS_REGISTER);

	special = malloc(sizeof(*special) * strlen("00000000000") + 1);
	SLL = malloc(sizeof(*SLL) * strlen("000000") + 1);

	if ((special == NULL) || (SLL == NULL)) {
		fprintf(stderr, "Unable to allocate memory !\n");
		exit(EXIT_FAILURE);
	}

	strcpy(special, "00000000000");
	strcpy(SLL, "000000");

	res_SLL = strcatTranslator5(res_SLL, special, rt_b, rd_b, sa_b, SLL);

	hexadecimal = binaryToHexa(hexadecimal, res_SLL);

	free(special);
	free(SLL);
	free(res_SLL);
	free(rt_b);
	free(sa_b);
	free(rd_b);

	return hexadecimal;
}