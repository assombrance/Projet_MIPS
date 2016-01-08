#include "Conversion.h"

#define HALF_BYTE 4

/* binaryToHexa_parsing : permet d'isoler des groupes de 4 bits dont 1 est non nul
  (à utiliser en complément avec binaryToHexa_mask qui rend une chaine du type 
   0000 0000 0001 0000 )
   input : une chaine de x bits
   output : une chaine de 4 bits													*/

char* Conversion_parsing(char* binary_masked) {

	unsigned int i = 0;
	unsigned j = 0;
	unsigned k;
	unsigned int flag = 0;
	unsigned int offset = 0;
	char* binary_parsed;
	char* nullString = NULL;
	int buffer = 0;

	binary_parsed = malloc(sizeof(*binary_parsed) * (HALF_BYTE + 1));
	nullString = malloc(sizeof(*nullString) * (strlen(binary_masked) + 1));

	for (k = 0; k < strlen(binary_masked); k++) {
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

	return binary_parsed;

}