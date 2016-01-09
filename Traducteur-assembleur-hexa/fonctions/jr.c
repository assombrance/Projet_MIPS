#include "jr.h"

char* jrHexa(char* instruction) {
	int i=0,rs;
	char* fin;
	char binaire[32],hexadecimal[8],ind_w[9],ind_b[27];
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage au add
		i++;
	}
	while((instruction[i]!=" ")&&(instruction[i]!="%t")){ //passage de l'add
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage à l'opérande (rs)
		i++;
	}
	rs = atoi(instruction[i]); //enregistrement de rs
	i++;
	if (instruction[i]!=" ")&&(instruction[i]!="%t")&&(instruction[i]!="%0")&&(instruction[i]!="#")){
		rs = 10*rs;
		rs += atoi(instruction[i]);
		i++;
	}
	sprintf(ind_w,"%d",ind);
	ind_b = decimalToBinary(ind_w);
	strcpy(binaire, "000010");
	strcpy(fin, "000000000000000001000");
	strcat(binaire,strcat(ind_b,fin);
	hexadecimal = binaryToHexa(binaire);
	return hexadecimal;
}