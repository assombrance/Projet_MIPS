#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*4 caractères de mnémonique et 1 caractère de tabulation*/
#define MAX_SIZE_MNEMO 4

void openSource(FILE* source);
FILE* removeCommentary(FILE* source);
char* convMnemonique(char* ligne);
