#include "bgtz.h"

char* bgtzHexa(char* instruction) {
	int i=0,rs,off,binaireInt;
	char* binaire,hexadecimal;
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage au add
		i++;
	}
	while((instruction[i]!=" ")&&(instruction[i]!="%t")){ //passage de l'add
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage à la deuxième opérande (rs)
		i++;
	}
	rs = atoi(instruction[i]; //enregistrement de rs
	i++;
	if (instruction[i]!=" ")&&(instruction[i]!="%t")||(instruction[i]!=",")){
		rs = 10*rs;
		rs += atoi(instruction[i]);
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")||(instruction[i]==",")){ //passage à la troisième opérande (off)
		i++;
	}
	off = atoi(instruction[i]; //enregistrement de off
	i++;
	if (instruction[i]!=" ")&&(instruction[i]!="%t")||(instruction[i]!="%0")){
		off = 10*off;
		off+ = atoi(instruction[i]);
		i++;
	}
	binaire = "000111%b00000%b00000100000",rs,off;
	binaireInt = atoi(binaire); //ça marche ? si non faire à la main :'(
	hexadecimal = "%X",binaireInt;
	return hexadecimal;
}