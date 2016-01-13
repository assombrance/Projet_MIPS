#include "fonctionsHexa.h"

char* orHexa(char* instruction) {
	int i=0,rs,rt,rd,binaireInt;
	char* fin;
	char binaire[32],hexadecimal[8],rs_w[3],rt_w[3],rd_w[3];
	char* rd_b;
	rd_b = malloc(sizeof(*rd_b)*7);
	char* rt_b;
	rt_b = malloc(sizeof(*rt_b)*7);
	char* rs_b;
	rs_b = malloc(sizeof(*rs_b)*7);
	fin = malloc(sizeof(*fin)*32);
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage au or
		i++;
	}
	while((instruction[i]!=" ")&&(instruction[i]!="%t")){ //passage de l'or
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage à la première opérande (rd)
		i++;
	}
	rd = atoi(instruction[i]); //enregistrement de rd
	i++;
	if((instruction[i]!=" ")&&(instruction[i]!="%t")&&(instruction[i]!=",")&&(instruction[i]!="#")){
		rd = 10*rd;
		rd += atoi(instruction[i]);
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")||(instruction[i]==",")){ //passage à la deuxième opérande (rs)
		i++;
	}
	rs = atoi(instruction[i]); //enregistrement de rs (décimal)
	i++;
	if((instruction[i]!=" ")&&(instruction[i]!="%t")&&(instruction[i]!=",")&&(instruction[i]!="#")){
		rs = 10*rs;
		rs += atoi(instruction[i]);
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")||(instruction[i]==",")){ //passage à la troisième opérande (rt)
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
	sprintf(rd_w,"%d",rd);
	rs_b = decimalToBinary(rs_w);
	rt_b = decimalToBinary(rt_w);
	rd_b = decimalToBinary(rd_w);
	strcpy(binaire, "000000");
	strcpy(fin, "00000100101");
	strcat(binaire,strcat(rs_b,strcat(rt_b,strcat(rd_b,fin))));
	hexadecimal = binaryToHexa(binaire);
	return hexadecimal;
}