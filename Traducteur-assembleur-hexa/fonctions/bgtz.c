#include "fonctionsHexa.h"

char* bgtzHexa(char* instruction) {
	int i=0,rs,off;
	char* special;
	char binaire[32],hexadecimal[8],rs_w[3],off_w[7];

	char* rs_b = NULL;
	char* off_b = NULL;

	rs_b = malloc(sizeof(*rs_b) * 7);
	off_b = malloc(sizeof(*rs_b) * 17);
	fin = malloc(sizeof(*special)*32);

	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage au add
		i++;
	}
	while((instruction[i]!=" ")&&(instruction[i]!="%t")){ //passage de l'add
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage à la deuxième opérande (rs)
		i++;
	}
	rs = atoi(instruction[i]); //enregistrement de rs
	i++;
	if((instruction[i]!=" ")||(instruction[i]!="%t")||(instruction[i]!=",")){
		rs = 10*rs;
		rs += atoi(instruction[i]);
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")||(instruction[i]==",")){ //passage à la troisième opérande (off)
		i++;
	}
	off = atoi(instruction[i]); //enregistrement de off
	i++;
	while((instruction[i]!=" ")||(instruction[i]!="%t")||(instruction[i]!="%0")||(instruction[i]!="#")){
		off = 10*off;
		off+ = atoi(instruction[i]);
		i++;
	}
	sprintf(rs_w,"%d",rs);
	sprintf(off_w,"%d",off);
	rs_b = decimalToBinary(rs_w);
	off_b = decimalToBinary(off_w);
	strcpy(binaire, "000111");
	strcpy(special, "00000");
	strcat(binaire,strcat(rs_b,strcat(special,off)));
	hexadecimal = binaryToHexa(binaire);
	return hexadecimal;
}