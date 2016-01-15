#include "fonctionsHexa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addHexa(char* instruction) {

	unsigned int i = 0,j=0;
	int rs, rt, rd, binaireInt;
	char* fin;
	char binaire[32];
	char rs_w[3];
	char rt_w[3];
	char rd_w[3];

	char* rs_b = NULL;
	char* rt_b = NULL;
	char* rd_b = NULL;
	char* hexadecimal = NULL;

	rs_b = malloc(sizeof(*rs_b) * 7);
	rt_b = malloc(sizeof(*rt_b) * 7);
	rd_b = malloc(sizeof(*rd_b) * 7);
	hexadecimal = malloc(sizeof(*hexadecimal) * 8);
	fin = malloc(sizeof(fin) * 32);

	while ((instruction[i] == ' ') || (instruction[i] == '%t')) { //passage au add
		i++;
	}
	while ((instruction[i] != ' ' ) && (instruction[i] != '%t')) { //passage de l'add
		i++;
	}
	while ((instruction[i] == ' ') || (instruction[i] == '%t')) { //passage à la première opérande (rd)
		i++;
	}
	rd_w[0] = instruction[i];
	i++;j++;
	if ((instruction[i] != ' ') && (instruction[i] != '%t') && (instruction[i] != ',') && (instruction[i] != '#')) {
		rd_w[1] = instruction[i];
		i++;j++;
	}
	rd_w[j] = '\0';j = 0;
	while ((instruction[i] == ' ') || (instruction[i] == '%t') || (instruction[i] == ',')) { //passage à la deuxième opérande (rs)
		i++;
	}
	rs_w[0] = instruction[i];
	i++;j++;
	if ((instruction[i] != ' ') && (instruction[i] != '%t') && (instruction[i] != ',') && (instruction[i] != '#')) {
		rs_w[1] = instruction[i];
		i++;j++;
	}
	rs_w[j] = '\0';j = 0;
	while ((instruction[i] == ' ') || (instruction[i] == '%t') || (instruction[i] == ',')) { //passage à la troisième opérande (rt)
		i++;
	}
	rt_w[0] = instruction[i];
	i++;j++;
	if ((instruction[i] != ' ') && (instruction[i] != '%t') && (instruction[i] != '%0') && (instruction[i] != '#')) {
		rt_w[1] = instruction[i];
		i++;j++;
	}
	rt_w[j] = '\0';
	i++;
	rs_b = decimalToBinary(rs_w);
	rt_b = decimalToBinary(rt_w);
	rd_b = decimalToBinary(rd_w);

	strcpy(binaire, "000000");
	strcpy(fin, "00000100000");

	strcat(binaire, strcat(rs_b, strcat(rt_b, strcat(rd_b, fin))));
	hexadecimal = binaryToHexa(binaire);

	free(rs_b);
	free(rt_b);
	free(rd_b);

	return hexadecimal;
}