#include "and.h"

char* andHexa(char* instruction) {
	int i=0,rs,rt,rd;
	char* fin;
	char binaire[32],hexadecimal[8],rs_w[3],rt_w[3],rd_w[3],rs_b[7],rt_b[7],rd_b[7];
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage au and
		i++;
	}
	while((instruction[i]!=" ")&&(instruction[i]!="%t")){ //passage de l'and
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage à la première opérande (rd)
		i++;
	}
	rd = atoi(instruction[i]); //enregistrement de rd
	i++;
	if (instruction[i]!=" ")&&(instruction[i]!="%t")||(instruction[i]!=",")){
		rd = 10*rd;
		rd += atoi(instruction[i]);
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")||(instruction[i]==",")){ //passage à la deuxième opérande (rs)
		i++;
	}
	rs = atoi(instruction[i]); //enregistrement de rs
	i++;
	if (instruction[i]!=" ")&&(instruction[i]!="%t")&&(instruction[i]!=",")){
		rs = 10*rs;
		rs += atoi(instruction[i]);
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")||(instruction[i]==",")){ //passage à la troisième opérande (rt)
		i++;
	}
	rt = atoi(instruction[i]); //enregistrement de rt
	i++;
	if (instruction[i]!=" ")&&(instruction[i]!="%t")&&(instruction[i]!="%0")&&(instruction[i]!="#")){
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
	strcpy(fin, "00000100100");
	strcat(binaire,strcat(rs_b,strcat(rt_b,strcat(rd_b,fin))));
	hexadecimal = binaryToHexa(binaire);
	return hexadecimal;
}