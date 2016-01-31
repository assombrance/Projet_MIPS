#include "fonctionsHexa.h"
#include "Conversion.h"

/* xor rd, rs, rt */

char* xorHexa(char* res, char* instruction) {
	
	unsigned int i = 0;
	int rs,rt,rd;
	char* rs_b = NULL;
	char* rt_b = NULL;
	char* rd_b = NULL;
	char* XOR = NULL;
	char* special = NULL;
	char* res_XOR = NULL;
	char* hexadecimal = res;


	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	rd = atoiTranslator(instruction, i); /*enregistrement de rd*/
	i++;

	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	rs = atoiTranslator(instruction, i); /*enregistrement de rs*/
	i++;
	
	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	rt = atoiTranslator(instruction, i); /*enregistrement de rt*/
	
	rs_b = decimalToBinary(rs_b, rs);
	rt_b = decimalToBinary(rt_b, rt);
	rd_b = decimalToBinary(rd_b, rd);

	rs_b = normalizeLengthOfField(rs_b, ADDRESS_REGISTER);
	rt_b = normalizeLengthOfField(rt_b, ADDRESS_REGISTER);
	rd_b = normalizeLengthOfField(rd_b, ADDRESS_REGISTER);

	special = malloc(sizeof(*special) * strlen("000000") + 1);
	XOR = malloc(sizeof(*XOR) * strlen("00000100110") + 1);


	if ((XOR == NULL) || (special == NULL)) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	strcpy(XOR, "00000100110");
	strcpy(special, "000000");

	res_XOR = strcatTranslator5(res_XOR, special, rs_b, rt_b, rd_b, XOR);
	hexadecimal = binaryToHexa(hexadecimal, res_XOR);

	free(XOR);
	free(special);
	free(res_XOR);
	free(rt_b);
	free(rs_b);
	free(rd_b);
	
	return hexadecimal;
}