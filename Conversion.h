/* Standard libraries */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define HALF_BYTE 4
/*Taille de la plus grande instruction 26 bits, soit 2^25*/
#define SIZE_MAX 10

char* binaryToHexa(char* binary);
char* decimalToBinary(int decimal);

char* Conversion_mask(unsigned int lenght, unsigned int offset, unsigned int nb);
char* Conversion_parsing(char* binary_masked);
char Conversion_binaryHexa(char* binary_parsed);
char* Conversion_ET(char* resBinary, char* mask);
char* Conversion_normalizeLength(char* binary);

char* Conversion_decimalBinary(int decimal);
char* Conversion_binaryAddition(char* binary_1, char* binary_2);
char* Conversion_equalizingLength(char* binary_1, char* binary_2);