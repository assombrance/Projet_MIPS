#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

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

// fonctions utilitaires

void miseEnForme(char*, char*);
int taille (char*);
void convMnemoniqueEmul(char*);