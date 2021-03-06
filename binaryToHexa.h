/* Standard librarys */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define HALF_BYTE = 4

char* binaryToHexa(char* binary);
int binaryToDecimal(char* binary);
char* binaryToHexa_mask(unsigned int lenght, unsigned int offset, unsigned int nb);
char* binaryToHexa_parsing(char* binary_masked);
char binaryToHexa_conversion(char* binary_parsed);
char* binaryToHexa_ET(char* resBinary, char* mask);
char* binaryToHexa_normalizeLength(char* binary);