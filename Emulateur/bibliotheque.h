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
void andEmul(char* instruction, char* memoire, int32_t* registres);
void luiEmul(char* instruction, char* memoire, int32_t* registres);
void lwEmul(char* instruction, char* memoire, int32_t* registres);
void mfhiEmul(char* instruction, char* memoire, int32_t* registres);
void mfloEmul(char* instruction, char* memoire, int32_t* registres);
void rotrEmul(char* instruction, char* memoire, int32_t* registres);
void sllEmul(char* instruction, char* memoire, int32_t* registres);
void sltEmul(char* instruction, char* memoire, int32_t* registres);
void srlEmul(char* instruction, char* memoire, int32_t* registres);
void swEmul(char* instruction, char* memoire, int32_t* registres);