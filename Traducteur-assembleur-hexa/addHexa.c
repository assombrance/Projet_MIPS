#include "Conversion.h"
#include "fonctionsHexa.h"

/* add rd, rs, rt */

char* addHexa(char* res, char* instruction) {

	unsigned int i = 0;
	int rs,rt,rd;
	char* rs_b = NULL;
	char* rt_b = NULL;
	char* rd_b = NULL;
	char* ADD = NULL;
	char* special = NULL;
	char* res_ADD = NULL;
	char* hexadecimal = res;

	printf("ADDHEXA : rs_b => %p (après init) \n", rs_b);
	printf("ADDHEXA : rt_b => %p (après init) \n", rt_b);
	printf("ADDHEXA : rd_b => %p (après init) \n", rd_b);
	printf("ADDHEXA : res_ADD => %p (après init) \n", res_ADD);
	printf("ADDHEXA : hexadecimal => %p (après init) \n", hexadecimal);



	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}
	/* atoi convertit instruction[i] (char) en entier (int)*/
	rd = atoiTranslator(instruction, i); /*enregistrement de rd*/
	printf("ADD : rd = %d \n", rd );
	printf("ADD: i = %d \n", i);
	i++;
	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}
	
	rs = atoiTranslator(instruction, i); /*enregistrement de rs (décimal)*/
	i++;	printf("ADD : rs = %d \n", rs);
	printf("ADD: i = %d \n", i);
	while (!isdigit(instruction[i]) && (instruction[i] != '-')) {
		i++;
	}
	
	rt = atoiTranslator(instruction, i); /*enregistrement de rt*/	
	printf("ADD : rt = %d \n", rt );
	printf("ADD: i = %d \n", i);

	printf("ADDHEXA : rs_b => %p (avant decimalToBinary) \n", rs_b);
	printf("ADDHEXA : rt_b => %p (avant decimalToBinary) \n", rt_b);
	printf("ADDHEXA : rd_b => %p (avant decimalToBinary) \n", rd_b);
	rs_b = decimalToBinary(rs_b, rs);
	rt_b = decimalToBinary(rt_b, rt);
	rd_b = decimalToBinary(rd_b, rd);
	printf("ADDHEXA : rs_b => %p (après decimalToBinary) \n", rs_b);
	printf("ADDHEXA : rt_b => %p (après decimalToBinary) \n", rt_b);
	printf("ADDHEXA : rd_b => %p (après decimalToBinary) \n", rd_b);

	getchar();
/*OK*/
	rs_b = normalizeLengthOfField(rs_b, ADDRESS_REGISTER);
	rt_b = normalizeLengthOfField(rt_b, ADDRESS_REGISTER);
	rd_b = normalizeLengthOfField(rd_b, ADDRESS_REGISTER);
/*OK*/
	printf("ADDHEXA : rs_b => %p (après normalizeLengthOfField) \n", rs_b);
	printf("ADDHEXA : rt_b => %p (après normalizeLengthOfField) \n", rt_b);
	printf("ADDHEXA : rd_b => %p (après normalizeLengthOfField) \n", rd_b);

	getchar();

	ADD = malloc(sizeof(*ADD) * strlen("00000100000") + 1);
	special = malloc(sizeof(*special) * strlen("000000") + 1);

	if ((ADD == NULL) || (special == NULL)) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	printf("ADDHEXA : ADD => %p (après malloc) \n", ADD);
	printf("ADDHEXA : special => %p (après malloc) \n", special);

	/* Copie la chaîne "000000" dans ADD */
	strcpy(ADD, "00000100000");
	strcpy(special, "000000");

	printf("ADDHEXA : ADD => %p (après strcpy) \n", ADD);
	printf("ADDHEXA : special => %p (après strcpy) \n", special);
/*OK*/

	res_ADD = strcatTranslator5(res_ADD, special, rs_b, rt_b, rd_b, ADD);
	stringTest(res_ADD);

	printf("ADDHEXA : res_ADD => %p (après strcatTranslator5) \n", res_ADD);

	getchar();

/*OK*/
	printf("ADDHEXA : hexadecimal => %p (avant binaryToHexa) \n", hexadecimal);
	hexadecimal = binaryToHexa(hexadecimal, res_ADD);
	printf("ADDHEXA : hexadecimal => %p (après binaryToHexa) \n", hexadecimal);

	free(ADD);
	free(special);
	free(rs_b);
	free(rt_b);
	free(rd_b);
	free(res_ADD);
	/* free(res_ADD)
	ATTENTION ! si on décommente cette ligne alors le programme segfault : double free memory corrupted */
	stringTest(hexadecimal);
	return hexadecimal;
}

