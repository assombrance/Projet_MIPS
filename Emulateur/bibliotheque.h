#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//fonctions de l'émulateur

void addEmul(char* instruction, char* memoire, int32_t* registres);		//fait
void xorEmul(char* instruction, char* memoire, int32_t* registres);		//fait
void subEmul(char* instruction, char* memoire, int32_t* registres);		//fait
void multEmul(char* instruction, char* memoire, int32_t* registres);	//fait
void orEmul(char* instruction, char* memoire, int32_t* registres);		//fait
void divEmul(char* instruction, char* memoire, int32_t* registres);		//fait
void addiEmul(char* instruction, char* memoire, int32_t* registres);	//fait
void andEmul(char* instruction, char* memoire, int32_t* registres);		//fait
void luiEmul(char* instruction, char* memoire, int32_t* registres);		//fait
void lwEmul(char* instruction, char* memoire, int32_t* registres);		//fait
void mfhiEmul(char* instruction, char* memoire, int32_t* registres);	//fait
void mfloEmul(char* instruction, char* memoire, int32_t* registres);	//fait
void rotrEmul(char* instruction, char* memoire, int32_t* registres);	//fait
void sllEmul(char* instruction, char* memoire, int32_t* registres);		//fait
void sltEmul(char* instruction, char* memoire, int32_t* registres);		//fait
void srlEmul(char* instruction, char* memoire, int32_t* registres);		//fait
void swEmul(char* instruction, char* memoire, int32_t* registres);		//fait
void jEmul(char* instruction, char* memoire, int32_t* registres);
void jrEmul(char* instruction, char* memoire, int32_t* registres);
void jalEmul(char* instruction, char* memoire, int32_t* registres);
void beqEmul(char* instruction, char* memoire, int32_t* registres);
void blezEmul(char* instruction, char* memoire, int32_t* registres);
void bneEmul(char* instruction, char* memoire, int32_t* registres);
void bgtzEmul(char* instruction, char* memoire, int32_t* registres);


// fonctions utilitaires

void miseEnForme(char*, char*);
int taille (char*);
void convMnemoniqueEmul(char*, char*, int32_t*);