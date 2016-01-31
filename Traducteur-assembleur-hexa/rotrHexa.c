#include "fonctionsHexa.h"
#include "Conversion.h"

/* rotr rd, rt, sa */

char* rotrHexa(char* res, char* instruction) {
	
	unsigned int i =0;
	int rd, rt, sa;
	char* res_ROTR = NULL;
	char* rd_b = NULL;
	char* rt_b = NULL;
	char* sa_b = NULL;
	char* special = NULL;
	char* SRL = NULL;
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
	
	rd_b = decimalToBinary(rd_b, rd);
	rt_b = decimalToBinary(rt_b, rt);	
	sa_b = decimalToBinary(sa_b, sa);

	rd_b = normalizeLengthOfField(rd_b, ADDRESS_REGISTER);
	rt_b = normalizeLengthOfField(rt_b, ADDRESS_REGISTER);
	sa_b = normalizeLengthOfField(sa_b, ADDRESS_REGISTER);

	special = malloc(sizeof(*special) * strlen("00000000001") + 1);
	SRL = malloc(sizeof(*SRL) * strlen("000010") + 1);

	if ((special == NULL) || (SRL == NULL)) {
		fprintf(stderr, "Unable to allocate memory !\n");
		exit(EXIT_FAILURE);
	}

	strcpy(special, "00000000001");
	strcpy(SRL, "000010");

	res_ROTR = strcatTranslator5(res_ROTR, special, rt_b, rd_b, sa_b, SRL);

	hexadecimal = binaryToHexa(hexadecimal, res_ROTR);

	free(special);
	free(SRL);
	free(res_ROTR);
	free(rd_b);
	free(rt_b);
	free(sa_b);

	return hexadecimal;
}