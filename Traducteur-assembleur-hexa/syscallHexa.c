#include "fonctionsHexa.h"
#include "Conversion.h"

/* SYSCALL */

char* syscallHexa(char* res, char* instruction) {
	
	char* SYSCALL = NULL;
	char* special = NULL;
	char* code = NULL;
	char* res_SYSCALL = NULL;
	char* hexadecimal = res;

	SYSCALL = malloc(sizeof(*SYSCALL) * strlen("001100") + 1);
	special = malloc(sizeof(*special) * strlen("000000") + 1);
	code = malloc(sizeof(*code) * strlen("*EXCEPTION OCCURED!*") + 1);

	if ((SYSCALL == NULL) || (special == NULL) || (code == NULL)) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	strcpy(SYSCALL, "001100");
	strcpy(special, "000000");
	strcpy(code, "*EXCEPTION OCCURED!*");

	res_SYSCALL = strcatTranslator3(res_SYSCALL, special, code, SYSCALL);
	
	/* Tester pour voir si binaryToHexa fonctionne avec des lettres */

	hexadecimal = binaryToHexa(hexadecimal, res_SYSCALL);

	free(special);
	free(code);
	free(SYSCALL);
	free(res_SYSCALL);

	return hexadecimal;
}