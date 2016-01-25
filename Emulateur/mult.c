#include "bibliotheque.h"

void multEmul(char* instruction,char* memoire,int32_t* registres) {

	int64_t result;
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

	result = (int64_t) registres[rt_instruction] * (int64_t) registres[rs_instruction];

	LO = result&0xffffffff;// LO et HI sont des registres spécialisés, ce sont 
	HI = result>>32;// les deux derniers éléments du tableau des registres

/*
	dans l'affichage, LO et HI peuvent être négatifs sans que le résultat le soit,
	il s'aggit juste de faire leur traduction en binaire puis leur complément à deux si négatifs.
	on les réassemble à ce moment et on retrouve alors le résultat correct
*/

	registres[33] = LO;
	registres[34] = HI;
}