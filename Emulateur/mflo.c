#include "fonctionsHexa.h"

char* mfloHexa(char* instruction) {
	int i=0,rs,rd;
	char* fin;
	char binaire[32],hexadecimal[8],rd_w[3];
	char* rd_b;
	rd_b = malloc(sizeof(*rd_b)*7);
	fin = malloc(sizeof(*fin)*32);
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage au mflo
		i++;
	}
	while((instruction[i]!=" ")&&(instruction[i]!="%t")){ //passage de l'mflo
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage à la première opérande (rd)
		i++;
	}
	rd = atoi(instruction[i]); //enregistrement de rd
	i++;
	if((instruction[i]!=" ")&&(instruction[i]!="%t")&&(instruction[i]!="%0")&&(instruction[i]!="#")){
		rd = 10*rd;
		rd += atoi(instruction[i]);
		i++;
	}
	sprintf(rd_w,"%d",rd);
	rd_b = decimalToBinary(rd_w);
	strcpy(binaire, "0000000000000000");
	strcpy(fin, "00000010010");
	strcat(binaire,strcat(rd_b,fin));
	hexadecimal = binaryToHexa(binaire);
	return hexadecimal;
}
