#include "binaryToHexa.h"

#define HALF_BYTE 4

char* binaryToHexa_parsing(char* binary_masked) {

	unsigned int i, j;
	unsigned int word_length = 4;
	unsigned int flag = 0;
	unsigned int offset = 0;
	char* binary_parsed;
	int buffer;

	binary_parsed = malloc(sizeof(*binary_parsed) * (word_length + 1));

	while (!flag) {

		if (binary_masked[i] == '0') {

			for (j = offset; j < offset + (word_length - 1); j++) {
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
			for (j = offset; j < offset + (word_length - 1); j++) {
				binary_parsed[j] = binary_masked[j];
			}
			binary_parsed[j + 1] = '\0';
			flag = 1;
		}	

		i++;
		offset += word_length - 1;
	}

	return binary_parsed;

}