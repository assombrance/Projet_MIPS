#include "Conversion.h"

/* Compare deux chaînes de caractères pour reconnaître des mnémoniques */

int strcmpTranslator(char* BUFFER, char* mnemonic) {

	unsigned int i = 0;
	unsigned int length_BUFFER, length_mnemonic;
	int flag = 0;

	length_BUFFER = strlen(BUFFER);
	length_mnemonic = strlen(mnemonic);

	printf("STRCMPTRANSLATOR : BUFFER => %p \n", BUFFER );
	printf("STRCMPTRANSLATOR : mnemonic = > %p \n", mnemonic);

	if ( length_mnemonic != length_BUFFER) {
		fprintf(stderr, "String to compare have not the same size\n" );
		exit(EXIT_FAILURE);
	} else {
		while ((BUFFER[i] != '\0') && (mnemonic[i] != '\0') ) {
			if (BUFFER[i] == mnemonic[i]) {
				flag++;
			} else {
				flag = 0;
			}
			i++;
			printf("STRCMPTRANSLATOR : flag = %d \n", flag );
		}
	}

	if (flag == length_BUFFER) {
		return 1;
	} else {
		return 0;
	}

}