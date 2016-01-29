#include "bibliotheque.h"

void jrEmul(char* instruction, char* memoire, int32_t* registres) {
	
	int i=0,j=0, rs_instruction;
	char rs_w[3];

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
	while ((instruction[i] != ' ') && (instruction[i] != '\t') && (instruction[i] != ',')) {
		rs_w[j] = instruction[i];
		i++;j++;
	}
	rs_w[j] = '\0';

	rs_instruction = atoi(rs_w);

	registres[rs_instruction] -= registres[rs_instruction]&3; //les deux derniers bites doivent être à 0 pour que l'adresse soit correcte

	registres[32] = registres[rs_instruction] - 4;
}