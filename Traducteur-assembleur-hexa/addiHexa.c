#include "fonctionsHexa.h"
#include "Conversion.h"

/* addi rt, rs, immediate */

char* addiHexa(char* res, char* instruction) {

	int rs,rt,imm;
	unsigned int i = 0;
	char* rs_b = NULL;
	char* rt_b = NULL;
	char* imm_b = NULL;
	char* ADDI = NULL;
	char* res_ADDI = NULL;
	char* hexadecimal = res; 

	printf("ADDIHEXA : rs_b => %p (après init) \n", rs_b);
	printf("ADDIHEXA : rt_b => %p (après init) \n", rt_b);
	printf("ADDIHEXA : imm_b => %p (après init) \n", imm_b);
	printf("ADDIHEXA : res_ADDI => %p (après init) \n", res_ADDI);
	printf("ADDIHEXA : hexadecimal => %p (après init) \n", hexadecimal);

	getchar();

	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	rt = atoiTranslator(instruction, i); /*enregistrement de rt*/
	printf("ADDIHEXA : rt = %d \n", rt );
	i++;
	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}

	rs = atoiTranslator(instruction, i); /*enregistrement de rs*/
	printf("ADDIHEXA : rs = %d \n", rs );
	i++;
	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}
	
	imm = atoiTranslator(instruction, i); /*enregistrement de imm*/
		printf("ADDIHEXA : imm = %d \n", imm );

	
	printf("ADDIHEXA : rs_b => %p (avant decimalToBinary) \n", rs_b);
	printf("ADDIHEXA : rt_b => %p (avant decimalToBinary) \n", rt_b);
	printf("ADDIHEXA : imm_b => %p (avant decimalToBinary) \n", imm_b);
	getchar();
	rs_b = decimalToBinary(rs_b, rs);
	rt_b = decimalToBinary(rt_b, rt);
	imm_b = decimalToBinary(imm_b, imm);
	printf("ADDIHEXA : rs_b => %p (après decimalToBinary) \n", rs_b);
	printf("ADDIHEXA : rt_b => %p (après decimalToBinary) \n", rt_b);
	printf("ADDIHEXA : imm_b => %p (après decimalToBinary) \n", imm_b);
	getchar();

	rs_b = normalizeLengthOfField(rs_b, ADDRESS_REGISTER);
	rt_b = normalizeLengthOfField(rt_b, ADDRESS_REGISTER);
	imm_b = normalizeLengthOfField(imm_b, IMMEDIATE);

	ADDI = malloc(sizeof(*ADDI) * strlen("001000") + 1);

	if ((ADDI == NULL)) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	strcpy(ADDI, "001000");

	res_ADDI = strcatTranslator4(res_ADDI, ADDI, rs_b, rt_b, imm_b);
	
	hexadecimal = binaryToHexa(hexadecimal, res_ADDI);

	free(ADDI);
	free(rs_b);
	free(rt_b);
	free(imm_b);
	free(res_ADDI);

	return hexadecimal;
}