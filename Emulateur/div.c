#include "fonctionsHexa.h"

char* divHexa(char* instruction) {
	int i=0,rs,rt,rd;
	char* fin;
	char binaire[32],hexadecimal[8],rs_w[3],rt_w[3];

	char* rs_b = NULL;
	char* rt_b = NULL;

	rs_b = malloc(sizeof(*rs_b) * 7);
	rt_b = malloc(sizeof(*rs_b) * 7);
	fin = malloc(sizeof(*fin)*32);

	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage au div
		i++;
	}
	while((instruction[i]!=" ")&&(instruction[i]!="%t")){ //passage de l'div
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage à la première opérande (rs)
		i++;
	}
	rs = atoi(instruction[i]); //enregistrement de rs
	i++;
	if((instruction[i]!=" ")&&(instruction[i]!="%t")&&(instruction[i]!=",")){
		rs = 10*rs;
		rs += atoi(instruction[i]);
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")||(instruction[i]==",")){ //passage à la deuxième opérande (rt)
		i++;
	}
	rt = atoi(instruction[i]); //enregistrement de rt
	i++;
	if((instruction[i]!=" ")&&(instruction[i]!="%t")&&(instruction[i]!="%0")&&(instruction[i]!="#")){
		rt = 10*rt;
		rt+ = atoi(instruction[i]);
		i++;
	}
	sprintf(rs_w,"%d",rs);
	sprintf(rt_w,"%d",rt);
	rs_b = decimalToBinary(rs_w);
	rt_b = decimalToBinary(rt_w);
	strcpy(binaire, "000000");
	strcpy(fin, "0000000000011010");
	strcat(binaire,strcat(rs_b,strcat(rt_b,fin)));
	hexadecimal = binaryToHexa(binaire);
	return hexadecimal;
}