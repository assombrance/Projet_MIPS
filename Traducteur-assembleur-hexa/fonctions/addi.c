#include "addi.h"

char* addIHexa(char* instruction) {
	int i=0,rs,rt,imm;
	char binaire[32],hexadecimal[8],rs_w[3],rt_w[3],imm_w[6],rs_b[7],rt_b[7],imm_b[17];
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage au add
		i++;
	}
	while((instruction[i]!=" ")&&(instruction[i]!="%t")){ //passage de l'add
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage à la première opérande (rt)
		i++;
	}
	rt = atoi(instruction[i]); //enregistrement de rt
	i++;
	if (instruction[i]!=" ")&&(instruction[i]!="%t")&&(instruction[i]!=",")){
		rt = 10*rt;
		rt += atoi(instruction[i]);
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")||(instruction[i]==",")){ //passage à la deuxième opérande (rs)
		i++;
	}
	rs = atoi(instruction[i]; //enregistrement de rs
	i++;
	if (instruction[i]!=" ")&&(instruction[i]!="%t")&&(instruction[i]!=",")){
		rs = 10*rs;
		rs += atoi(instruction[i]);
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")||(instruction[i]==",")){ //passage à la troisième opérande (imm)
		i++;
	}
	imm = atoi(instruction[i]; //enregistrement de imm
	i++;
	if (instruction[i]!=" ")&&(instruction[i]!="%t")&&(instruction[i]!="%0")&&(instruction[i]!="#")){
		imm = 10*imm;
		imm+ = atoi(instruction[i]);
		i++;
	}
	sprintf(rs_w,"%d",rs);
	sprintf(rt_w,"%d",rt);
	sprintf(imm_w,"%d",imm);
	rs_b = decimalToBinary(rs_w);
	rt_b = decimalToBinary(rt_w);
	imm_b = decimalToBinary(imm_w);
	strcpy(binaire, "001000");
	strcpy(fin, "00000100000");
	strcat(binaire,strcat(rs_b,strcat(rt_b,strcat(imm_b,fin))));
	hexadecimal = binaryToHexa(binaire);
	return hexadecimal;
}