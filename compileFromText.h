#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*4 caract�res de mn�monique et 1 caract�re de tabulation*/
#define MAX_SIZE_MNEMO 5

void openSource(FILE* source);
FILE* removeCommentary(FILE* source);
void convMnemonique(char* ligne);
