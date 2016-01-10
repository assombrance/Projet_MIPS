#include "fonctionsHexa.h"

char* lwHexa(char* instruction) {
	int i=0,rs,off,rt;
	char binaire[32],hexadecimal[8],off_w[6],rt_w[3],off_b[17],rt_b[7];
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage au lw
		i++;
	}
	while((instruction[i]!=" ")&&(instruction[i]!="%t")){ //passage de l'lw
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage à la première opérande (rt)
		i++;
	}
	rt = atoi(instruction[i]); //enregistrement de rt
	i++;
	if((instruction[i]!=" ")&&(instruction[i]!="%t")&&(instruction[i]!=",")){
		rt = 10*rt;
		rt += atoi(instruction[i]);
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")||(instruction[i]==",")){ //passage à la deuxième opérande (off)
		i++;
	}
	off = atoi(instruction[i]; //enregistrement de off
	i++;
	while((instruction[i]!=" ")&&(instruction[i]!="%t")&&(instruction[i]!="%0")&&(instruction[i]!="#")){
		off = 10*off;
		off+ = atoi(instruction[i]);
		i++;
	}
	sprintf(off_w,"%d",off);
	sprintf(rt_w,"%d",rt);
	off_b = decimalToBinary(off_w);
	rt_b = decimalToBinary(rt_w);
	strcpy(binaire, "10001100000");
	strcat(binaire,strcat(rt_b,off_b));
	hexadecimal = binaryToHexa(binaire);
	return hexadecimal;
}