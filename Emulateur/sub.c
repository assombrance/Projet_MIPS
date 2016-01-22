#include "bibliotheque.h"

void subEmul(char* instruction,char* memoire,int32_t* registres) {

	int32_t rs, rt, rd;
	int i=0,j=0, rt_instruction, rs_instruction, rd_instruction;
	char rs_w[3], rt_w[3], rd_w[3];

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
	while ((instruction[i] == ' ') || (instruction[i] == '\t') || (instruction[i] == ',')) { //passage à la troisième opérande (rt)
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
	rd_instruction = atoi(rd_w);
	rs_instruction = atoi(rs_w);

	registres[rd_instruction]=registres[rs_instruction]-registres[rt_instruction];
}