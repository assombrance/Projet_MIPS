#include "fonctionsHexa.h"

char* beqHexa(char* instruction) {
	int i=0,rs,rt,off;
	char binaire[32],hexadecimal[8],rs_w[3],rt_w[3],off_w[6],rs_b[7],rt_b[7],off_b[17];
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
	if((instruction[i]!=" ")&&(instruction[i]!="%t")&&(instruction[i]!=",")){
		rt = 10*rt;
		rt += atoi(instruction[i]);
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")||(instruction[i]==",")){ //passage à la deuxième opérande (rs)
		i++;
	}
	rs = atoi(instruction[i]); //enregistrement de rs
	i++;
	if((instruction[i]!=" ")&&(instruction[i]!="%t")&&(instruction[i]!=",")){
		rs = 10*rs;
		rs += atoi(instruction[i]);
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")||(instruction[i]==",")){ //passage à la troisième opérande (off)
		i++;
	}
	off = atoi(instruction[i]); //enregistrement de off
	i++;
	while((instruction[i]!=" ")&&(instruction[i]!="%t")&&(instruction[i]!="%0")&&(instruction[i]!="#")){
		off = 10*off;
		off+ = atoi(instruction[i]);
		i++;
	}
	sprintf(rs_w,"%d",rs);
	sprintf(rt_w,"%d",rt);
	sprintf(off_w,"%d",off);
	rs_b = decimalToBinary(rs_w);
	rt_b = decimalToBinary(rt_w);
	off_b = decimalToBinary(off_w);
	strcpy(binaire, "000100");
	strcat(binaire,strcat(rs_b,strcat(rt_b,off_b)));
	hexadecimal = binaryToHexa(binaire);
	return hexadecimal;
}