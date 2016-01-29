#include "bibliotheque.h"

void divEmul(char* instruction,char* memoire,int32_t* registres) {

	int i=0,j=0, rt_instruction, rs_instruction, LO, HI;
	char rs_w[3], rt_w[3];

	while ((instruction[i] == ' ') || (instruction[i] == '\t')) { //passage au add
		i++;
	}
	while ((instruction[i] != ' ' ) && (instruction[i] != '\t')) { //passage de l'add
		i++;
	}
	while ((instruction[i] == ' ') || (instruction[i] == '\t') || (instruction[i] == ',')) { //passage à la première opérande (rs)
		i++;
	}
	rs_w[0] = instruction[i];
	i++;j++;
	if ((instruction[i] != ' ') && (instruction[i] != '\t') && (instruction[i] != ',')) {
		rs_w[1] = instruction[i];
		i++;j++;
	}
	rs_w[j] = '\0';j = 0;
	while ((instruction[i] == ' ') || (instruction[i] == '\t') || (instruction[i] == ',')) { //passage à la seconde opérande (rt)
		i++;
	}
	rt_w[0] = instruction[i];
	i++;j++;
	if ((instruction[i] != ' ') && (instruction[i] != '\t') && (instruction[i] != '\0') && (instruction[i] != '#')) {
		rt_w[1] = instruction[i];
		i++;j++;
	}
	rt_w[j] = '\0';
	
	rt_instruction = atoi(rt_w);
	rs_instruction = atoi(rs_w);	

	LO = registres[rs_instruction]/registres[rt_instruction];// LO et HI sont des registres spécialisés, ce sont 
	HI = registres[rs_instruction]%registres[rt_instruction];// les deux derniers éléments du tableau des registres

	registres[33] = LO;
	registres[34] = HI;
}