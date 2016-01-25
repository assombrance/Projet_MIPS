#include "bibliotheque.h"

void mfhiEmul(char* instruction, char* memoire, int32_t* registres) {
	
	int i=0,j=0, rd_instruction;
	char rd_w[3];

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

	rd_instruction = atoi(rd_w);
	
	registres[rd_instruction]=registres[34];
}