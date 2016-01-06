#include "add.h"

char* addHexa(char* instruction) {
	int i=0,rs,rt,rd,binaireInt;
	char* binaire,hexadecimal;
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage au add
		i++;
	}
	while((instruction[i]!=" ")&&(instruction[i]!="%t")){ //passage de l'add
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage à la première opérande (rs)
		i++;
	}
	rs = atoi(instruction[i]; //enregistrement de rs
	i++;
	if (instruction[i]!=" ")&&(instruction[i]!="%t")||(instruction[i]!=",")){
		rs = 10*rs;
		rs += atoi(instruction[i]);
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")||(instruction[i]==",")){ //passage à la deuxième opérande (rt)
		i++;
	}
	rt = atoi(instruction[i]; //enregistrement de rt
	i++;
	if (instruction[i]!=" ")&&(instruction[i]!="%t")||(instruction[i]!="%0")){
		rt = 10*rt;
		rt+ = atoi(instruction[i]);
		i++;
	}
	binaire = "000000%b%b0000000000011010",rs,rt,rd;
	binaireInt = atoi(binaire); //ça marche ? si non faire à la main :'(
	hexadecimal = "%X",binaireInt;
	return hexadecimal;
}