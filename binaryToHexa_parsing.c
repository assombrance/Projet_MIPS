#include "binaryToHexa.h"

#define HALF_BYTE 4

/* binaryToHexa_parsing : permet d'isoler des groupes de 4 bits dont 1 est non nul
  (à utiliser en complément avec binaryToHexa_mask qui rend une chaine du type 
   0000 0000 0001 0000 )
   input : une chaine de x bits
   output : une chaine de 4 bits													*/

char* binaryToHexa_parsing(char* binary_masked) {

	unsigned int i = 0;
	unsigned j;
	unsigned int flag = 0;
	unsigned int offset = 0;
	char* binary_parsed;
	int buffer = 0;

	binary_parsed = malloc(sizeof(*binary_parsed) * (HALF_BYTE + 1));

	while (!flag) {

		if (binary_masked[i] == '0') {

			for (j = offset; j < offset + (HALF_BYTE - 1); j++) {
				buffer += binary_masked[j];
				binary_parsed[j] = binary_masked[j];
			}

			binary_parsed[j + 1] = '\0';

			if (buffer != 0) {
				flag = 1;
			}
			else {
				buffer = 0;
			}
		}
		else {
			for (j = offset; j < offset + (HALF_BYTE - 1); j++) {
				binary_parsed[j] = binary_masked[j];
			}
			binary_parsed[j + 1] = '\0';
			flag = 1;
		}	

		i++;
		offset += HALF_BYTE - 1;
	}

	return binary_parsed;

}