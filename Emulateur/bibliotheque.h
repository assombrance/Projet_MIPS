#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
//#include "CompileFromText.h"
//#include "Conversion.h"


void addEmul(char* instruction, char* memoire, int32_t* registres);
void xorEmul(char* instruction, char* memoire, int32_t* registres);
void subEmul(char* instruction, char* memoire, int32_t* registres);
void orEmul(char* instruction, char* memoire, int32_t* registres);
void divEmul(char* instruction, char* memoire, int32_t* registres);
void addiEmul(char* instruction, char* memoire, int32_t* registres);