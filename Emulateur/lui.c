#include "bibliotheque.h"

void luiEmul(char* instruction,char* memoire,int32_t* registres) {

	int i=0,j=0, rt_instruction, imm_instruction;
	char rt_w[3], imm_w[7];

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
	while ((instruction[i] == ' ') || (instruction[i] == '\t') || (instruction[i] == ',')) { //passage à la deuxième opérande (imm)
		i++;
	}
	imm_w[0] = instruction[i];
	i++;j++;
	while ((instruction[i] != ' ') && (instruction[i] != '\t') && (instruction[i] != ',')) {
		imm_w[1] = instruction[i];
		i++;j++;
	}
	imm_w[j] = '\0';
	
	rt_instruction = atoi(rt_w);
	imm_instruction = atoi(imm_w);

	registres[rt_instruction]=imm_instruction;
}