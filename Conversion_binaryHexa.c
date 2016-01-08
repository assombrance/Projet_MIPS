#include "Conversion.h"

char Conversion_binaryHexa(char* binary_parsed) {

	char resHexa;

	if (strcmp(binary_parsed, "0000") == 0) {
		resHexa = '0';
	}
	else if (strcmp(binary_parsed, "0001") == 0) {
		resHexa = '1';
	}
	else if (strcmp(binary_parsed, "0010") == 0) {
		resHexa = '2';
	}
	else if (strcmp(binary_parsed, "0011") == 0) {
		resHexa = '3';
	}
	else if (strcmp(binary_parsed, "0100") == 0) {
		resHexa = '4';
	}
	else if (strcmp(binary_parsed, "0101") == 0) {
		resHexa = '5';
	}
	else if (strcmp(binary_parsed, "0110") == 0) {
		resHexa = '6';
	}
	else if (strcmp(binary_parsed, "0111") == 0) {
		resHexa = '7';
	}
	else if (strcmp(binary_parsed, "1000") == 0) {
		resHexa = '8';
	}
	else if (strcmp(binary_parsed, "1001") == 0) {
		resHexa = '9';
	}
	else if (strcmp(binary_parsed, "1010") == 0) {
		resHexa = 'A';
	}
	else if (strcmp(binary_parsed, "1011") == 0) {
		resHexa = 'B';
	}
	else if (strcmp(binary_parsed, "1100") == 0) {
		resHexa = 'C';
	}
	else if (strcmp(binary_parsed, "1101") == 0) {
		resHexa = 'D';
	}
	else if (strcmp(binary_parsed, "1110") == 0) {
		resHexa = 'E';
	}
	else {
		resHexa = 'F';
	}

	return resHexa;
}
