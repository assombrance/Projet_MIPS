#include "fonctionsHexa.h"

char* luiHexa(char* instruction) {
	int i=0,rs,imm,rt;
	char binaire[32],hexadecimal[8],imm_w[6],rt_w[3];

	char* imm_b = NULL;
	char* rt_b = NULL;
	imm_b = malloc(sizeof(*imm_b) * 27);
	rt_b = malloc(sizeof(*rt_b) * 7);
	
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage au lui
		i++;
	}
	while((instruction[i]!=" ")&&(instruction[i]!="%t")){ //passage de l'lui
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
	while((instruction[i]==" ")||(instruction[i]=="%t")||(instruction[i]==",")){ //passage à la deuxième opérande (imm)
		i++;
	}
	imm = atoi(instruction[i]; //enregistrement de imm
	i++;
	while((instruction[i]!=" ")&&(instruction[i]!="%t")&&(instruction[i]!="%0")&&(instruction[i]!="#")){
		imm = 10*imm;
		imm+ = atoi(instruction[i]);
		i++;
	}
	sprintf(imm_w,"%d",imm);
	sprintf(rt_w,"%d",rt);
	imm_b = decimalToBinary(imm_w);
	rt_b = decimalToBinary(rt_w);
	strcpy(binaire, "00111100000");
	strcat(binaire,strcat(rt_b,imm_b));
	hexadecimal = binaryToHexa(binaire);
	return hexadecimal;
}
