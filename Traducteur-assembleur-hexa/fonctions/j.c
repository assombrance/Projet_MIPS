#include "fonctionsHexa.h"

char* jHexa(char* instruction) {
	int i=0,ind;
	char binaire[32],hexadecimal[8],ind_w[9],ind_b[27];
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage au add
		i++;
	}
	while((instruction[i]!=" ")&&(instruction[i]!="%t")){ //passage de l'add
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage à l'opérande (ind)
		i++;
	}
	ind = atoi(instruction[i]); //enregistrement de ind
	i++;
	while((instruction[i]!=" ")&&(instruction[i]!="%t")&&(instruction[i]!="%0")&&(instruction[i]!="#")){
		ind = 10*ind;
		ind += atoi(instruction[i]);
		i++;
	}
	sprintf(ind_w,"%d",ind);
	ind_b = decimalToBinary(ind_w);
	strcpy(binaire, "000010");
	strcat(binaire,ind_b);
	hexadecimal = binaryToHexa(binaire);
	return hexadecimal;
}