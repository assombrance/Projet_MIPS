#include "jr.h"

char* jrHexa(char* instruction) {
	int i=0,rs,binaireInt;
	char* binaire,hexadecimal;
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage au add
		i++;
	}
	while((instruction[i]!=" ")&&(instruction[i]!="%t")){ //passage de l'add
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage à l'opérande (rs)
		i++;
	}
	rs = atoi(instruction[i]; //enregistrement de rs
	i++;
	if (instruction[i]!=" ")&&(instruction[i]!="%t")||(instruction[i]!="%0")){
		rs = 10*rs;
		rs += atoi(instruction[i]);
		i++;
	}
	binaire = "000000%b000000000000000001000",rs; //hint à 0 pour l'architecture 1 ...
	binaireInt = atoi(binaire); //ça marche ? si non faire à la main :'(
	hexadecimal = "%X",binaireInt;
	return hexadecimal;
}