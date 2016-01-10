#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 4

void openSource(FILE* source);
FILE* removeCommentary(FILE* source);
int convMnemo(char* ligne);
