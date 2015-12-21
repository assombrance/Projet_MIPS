#include "binaryToHexa.h"

char binaryToHexa_conversion(char* binary_parsed) {

	char res;

	if (binary_parsed == "1010") {
		res = 'A';
	}
	else if (binary_parsed == "1011") {
		res = 'B';
	}
	else if (binary_parsed == "1100") {
		res = 'C';
	}
	else if (binary_parsed == "1101") {
		res = 'D';
	}
	else if (binary_parsed == "1110") {
		res = 'E';
	}
	else if (binary_parsed == "1111") {
		res = 'F';
	}
	else {
		return 0;
	}

	return res;
}