/* Standard libraries */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define HALF_BYTE 4
/*Taille de la plus grande instruction 26 bits, soit 2^25*/
#define SIZE_MAX 10

char* binaryToHexa(char* binary);
char* decimalToBinary(int decimal);

char* Cmask(unsigned int lenght, unsigned int offset, unsigned int nb);
char* parsing(char* binary_masked);
char binaryHexa(char* binary_parsed);
char* ET(char* resBinary, char* mask);
char* normalizeLength(char* binary);

char* decimalBinary(int decimal);
char* binaryAddition(char* binary_1);
char* equalizingLength(char* binary_1, char* binary_2);
char* removeZero(char* binary);