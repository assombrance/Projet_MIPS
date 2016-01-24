#include "Conversion.h"

/*************************************************************************************/
/*                                parsing                                            */
/*************************************************************************************/

/* Permet de sélectionner un groupe de 4 bits dans une châine                        */

char* parsing(char* binary_parsed, char* binary_masked) {

	unsigned int i = 0;
	unsigned j = 0;
	unsigned k;
	unsigned int flag = 0;
	unsigned int offset = 0;
	unsigned int length_binaryMasked;
	int buffer = 0;
	char* nullString = NULL;

	/* La fonction strlen ne prend pas en compte le caractère de fin de chaine dans son renvoi */
	nullString = malloc(sizeof(*nullString) * strlen(binary_masked) + 1);
	
	length_binaryMasked = strlen(binary_masked);

	for (k = 0; k < length_binaryMasked; k++) {
		nullString[k] = '0';
	}
	nullString[k] = '\0';

	if (strcmp(binary_masked, nullString) != 0) {

		while (!flag) {

			if (binary_masked[i] == '0') {

				for (j = offset; j < offset + HALF_BYTE; j++) {
					if (binary_masked[j] == '1') { /* sinon il considère le caractère ASCII donc 48 pour '0'...*/
						buffer += 1;
					}
					binary_parsed[j - offset] = binary_masked[j];
				}

				binary_parsed[j - offset] = '\0';

				if (buffer != 0) {
					flag = 1;
				}
				else {
					buffer = 0;
				}
			}
			else {
				for (j = offset; j < offset + HALF_BYTE; j++) {
					binary_parsed[j - offset*j] = binary_masked[j];
				}
				binary_parsed[j - offset] = '\0';
				flag = 1;
			}

			i++;
			offset += HALF_BYTE;
		}
	}
	else {
		for (k = 0; k < HALF_BYTE; k++) {
			binary_parsed[k] = '0';
		}
		binary_parsed[k] = '\0';
	}

	free(nullString);
	
	return binary_parsed;
}