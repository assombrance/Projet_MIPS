#include "fonctionsHexa.h"

char* srlHexa(char* instruction) {
	int i=0,rt,sa,rd,binaireInt;
	char* fin;
	char binaire[32],hexadecimal[8],rt_w[3],sa_w[3],rd_w[3],rt_b[7],sa_b[7],rd_b[7];
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage au srl
		i++;
	}
	while((instruction[i]!=" ")&&(instruction[i]!="%t")){ //passage de l'srl
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
	while((instruction[i]==" ")||(instruction[i]=="%t")||(instruction[i]==",")){ //passage à la deuxième opérande (rt)
		i++;
	}
	rt = atoi(instruction[i]); //enregistrement de rt (décimal)
	i++;
	if((instruction[i]!=" ")&&(instruction[i]!="%t")&&(instruction[i]!=",")&&(instruction[i]!="#")){
		rt = 10*rt;
		rt += atoi(instruction[i]);
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")||(instruction[i]==",")){ //passage à la troisième opérande (sa)
		i++;
	}
	sa = atoi(instruction[i]); //enregistrement de sa
	i++;
	if((instruction[i]!=" ")&&(instruction[i]!="%t")&&(instruction[i]!="%0")&&(instruction[i]!="#")){
		sa = 10*sa;
		sa+ = atoi(instruction[i]);
		i++;
	}
	sprintf(rt_w,"%d",rt);
	sprintf(sa_w,"%d",sa);
	sprintf(rd_w,"%d",rd);
	rt_b = decimalToBinary(rt_w);
	sa_b = decimalToBinary(sa_w);
	rd_b = decimalToBinary(rd_w);
	strcpy(binaire, "00000000000");
	strcpy(fin, "000010");
	strcat(binaire,strcat(rt_b,strcat(rd_b,strcat(sa_b,fin))));
	hexadecimal = binaryToHexa(binaire);
	return hexadecimal;
}