#include "bibliotheque.h"

void addiEmul(char* instruction,char* memoire,int32_t* registres) {

	int32_t rs, rt, imm;
	int i=0,j=0, rt_instruction, rs_instruction;
	char rs_w[3], rt_w[3], imm_w[6];

	while ((instruction[i] == ' ') || (instruction[i] == '\t')) { //passage au add
		i++;
	}
	while ((instruction[i] != ' ' ) && (instruction[i] != '\t')) { //passage de l'add
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
	while ((instruction[i] == ' ') || (instruction[i] == '\t') || (instruction[i] == ',')) { //passage à la deuxième opérande (rs)
		i++;
	}
	rs_w[0] = instruction[i];
	i++;j++;
	if ((instruction[i] != ' ') && (instruction[i] != '\t') && (instruction[i] != ',')) {
		rs_w[1] = instruction[i];
		i++;j++;
	}
	rs_w[j] = '\0';j = 0;
	while ((instruction[i] == ' ') || (instruction[i] == '\t') || (instruction[i] == ',')) { //passage à la troisième opérande (imm)
		i++;
	}
	imm_w[0] = instruction[i];
	i++;j++;
	while ((instruction[i] != ' ') && (instruction[i] != '\t') && (instruction[i] != '\0') && (instruction[i] != '#')) {
		imm_w[j] = instruction[i];
		i++;j++;
	}
	imm_w[j] = '\0';
	
	rt_instruction = atoi(rt_w);
	imm = atoi(imm_w);
	rs_instruction = atoi(rs_w);

	registres[rt_instruction]=imm+registres[rs_instruction];
}