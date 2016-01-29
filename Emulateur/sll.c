#include "bibliotheque.h"

void sllEmul(char* instruction, char* memoire, int32_t* registres) {
	
	int i=0,j=0, sa_instruction, rt_instruction, rd_instruction;
	char rt_w[3], sa_w[3], rd_w[3];

	while ((instruction[i] == ' ') || (instruction[i] == '\t')) { //passage au add
		i++;
	}
	while ((instruction[i] != ' ' ) && (instruction[i] != '\t')) { //passage de l'add
		i++;
	}
	while ((instruction[i] == ' ') || (instruction[i] == '\t')) { //passage à la première opérande (rd)
		i++;
	}
	rd_w[0] = instruction[i];
	i++;j++;
	if ((instruction[i] != ' ') && (instruction[i] != '\t') && (instruction[i] != ',')) {
		rd_w[1] = instruction[i];
		i++;j++;
	}
	rd_w[j] = '\0';j = 0;
	while ((instruction[i] == ' ') || (instruction[i] == '\t') || (instruction[i] == ',')) { //passage à la deuxième opérande (rt)
		i++;
	}
	rt_w[0] = instruction[i];
	i++;j++;
	if ((instruction[i] != ' ') && (instruction[i] != '\t') && (instruction[i] != ',')) {
		rt_w[1] = instruction[i];
		i++;j++;
	}
	rt_w[j] = '\0';j = 0;
	while ((instruction[i] == ' ') || (instruction[i] == '\t') || (instruction[i] == ',')) { //passage à la troisième opérande (sa)
		i++;
	}
	sa_w[0] = instruction[i];
	i++;j++;
	if ((instruction[i] != ' ') && (instruction[i] != '\t') && (instruction[i] != '\0') && (instruction[i] != '#')) {
		sa_w[1] = instruction[i];
		i++;j++;
	}
	sa_w[j] = '\0';

	sa_instruction = atoi(sa_w);
	rd_instruction = atoi(rd_w);
	rt_instruction = atoi(rt_w);

	registres[rd_instruction]=registres[rt_instruction]<<sa_instruction;
}