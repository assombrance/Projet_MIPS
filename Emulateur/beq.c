#include "bibliotheque.h"

void beqEmul(char* instruction, char* memoire, int32_t* registres) {
	
	int i=0,j=0, off_instruction, rt_instruction, rs_instruction;
	char rt_w[3], off_w[7], rs_w[3];

	while ((instruction[i] == ' ') || (instruction[i] == '\t')) { //passage au add
		i++;
	}
	while ((instruction[i] != ' ' ) && (instruction[i] != '\t')) { //passage de l'add
		i++;
	}
	while ((instruction[i] == ' ') || (instruction[i] == '\t')) { //passage à la première opérande (rs)
		i++;
	}
	rs_w[0] = instruction[i];
	i++;j++;
	if ((instruction[i] != ' ') && (instruction[i] != '\t') && (instruction[i] != ',')) {
		rs_w[1] = instruction[i];
		i++;j++;
	}
	rs_w[j] = '\0';j = 0;
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
	while ((instruction[i] == ' ') || (instruction[i] == '\t') || (instruction[i] == ',')) { //passage à la troisième opérande (off)
		i++;
	}
	off_w[0] = instruction[i];
	i++;j++;
	while ((instruction[i] != ' ') && (instruction[i] != '\t') && (instruction[i] != '\0') && (instruction[i] != '#')) {
		off_w[j] = instruction[i];
		i++;j++;
	}
	off_w[j] = '\0';

	off_instruction = atoi(off_w);
	rs_instruction = atoi(rs_w);
	rt_instruction = atoi(rt_w);

	if ( registres[rs_instruction] == registres[rt_instruction] ) registres[32] += (off_instruction<<2) - 4;
}