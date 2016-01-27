#include "bibliotheque.h"

void jEmul(char* instruction, char* memoire, int32_t* registres) {
	
	int i=0,j=0, ind_instruction;
	char ind_w[9];

	while ((instruction[i] == ' ') || (instruction[i] == '\t')) { //passage au add
		i++;
	}
	while ((instruction[i] != ' ' ) && (instruction[i] != '\t')) { //passage de l'add
		i++;
	}
	while ((instruction[i] == ' ') || (instruction[i] == '\t')) { //passage à la première opérande (ind)
		i++;
	}
	ind_w[0] = instruction[i];
	i++;j++;
	while ((instruction[i] != ' ') && (instruction[i] != '\t') && (instruction[i] != ',')) {
		ind_w[j] = instruction[i];
		i++;j++;
	}
	ind_w[j] = '\0';

	ind_instruction = atoi(ind_w);

	registres[32] = (registres[32] & 4026531840) + (ind_instruction<<2); //4026531840 = 11110000000000000000000000000000 pour le masque
}