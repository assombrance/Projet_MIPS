#include "bibliotheque.h"

void swEmul(char* instruction,char* memoire,int32_t* registres) {

	int i=0,j=0, rt_instruction, off_instruction;
	char rt_w[3], off_w[7];

	while ((instruction[i] == ' ') || (instruction[i] == '\t')) { //passage au sw
		i++;
	}
	while ((instruction[i] != ' ' ) && (instruction[i] != '\t')) { //passage de l'sw
		i++;
	}
	while ((instruction[i] == ' ') || (instruction[i] == '\t')) { //passage à la première opérande (rt)
		i++;
	}
	rt_w[0] = instruction[i];
	i++;j++;
	if ((instruction[i] != ' ') && (instruction[i] != '\t') && (instruction[i] != ',')) {
		rt_w[1] = instruction[i];
		i++;j++;
	}
	rt_w[j] = '\0';j = 0;
	while ((instruction[i] == ' ') || (instruction[i] == '\t') || (instruction[i] == ',')) { //passage à la deuxième opérande (off)
		i++;
	}
	off_w[0] = instruction[i];
	i++;j++;
	while ((instruction[i] != ' ') && (instruction[i] != '\t') && (instruction[i] != ',')) {
		off_w[1] = instruction[i];
		i++;j++;
	}
	off_w[j] = '\0';
	
	rt_instruction = atoi(rt_w);
	off_instruction = atoi(off_w);

	registres[rt_instruction]=memoire[off];
}