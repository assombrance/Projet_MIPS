#include "binaryToHexa.h"

#define HALF_BYTE 4

char* binaryToHexa_parsing(char* binary) {

	int i;
	char* res;

	for (i = 0; i < HALF_BYTE; i++) {
		res = binary[i] << 1;
	}


}