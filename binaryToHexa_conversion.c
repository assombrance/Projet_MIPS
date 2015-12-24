#include "binaryToHexa.h"

char binaryToHexa_conversion(char* binary_parsed) {

	char resHexa;

	if (binary_parsed == "0000") {
		resHexa = '0';
	}
	else if (binary_parsed == "0001") {
		resHexa = '1';
	}
	else if (binary_parsed == "0010") {
		resHexa = '2';
	}
	else if (binary_parsed == "0011") {
		resHexa = '3';
	}
	else if (binary_parsed == "0100") {
		resHexa = '4';
	}
	else if (binary_parsed == "0101") {
		resHexa = '5';
	}
	else if (binary_parsed == "0110") {
		resHexa = '6';
	}
	else if (binary_parsed == "0111") {
		resHexa = '7';
	}
	else if (binary_parsed == "1000") {
		resHexa = '8';
	}
	else if (binary_parsed == "1001") {
		resHexa = '9';
	}
	else if (binary_parsed == "1010") {
		resHexa = 'A';
	}
	else if (binary_parsed == "1011") {
		resHexa = 'B';
	}
	else if (binary_parsed == "1100") {
		resHexa = 'C';
	}
	else if (binary_parsed == "1101") {
		resHexa = 'D';
	}
	else if (binary_parsed == "1110") {
		resHexa = 'E';
	}
	else {
		resHexa = 'F';
	}

	return resHexa;
}
