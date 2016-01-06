#include "j.h"

char* jHexa(char* instruction) {
	int i=0,ind,binaireInt;
	char* binaire,hexadecimal;
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage au add
		i++;
	}
	while((instruction[i]!=" ")&&(instruction[i]!="%t")){ //passage de l'add
		i++;
	}
	while((instruction[i]==" ")||(instruction[i]=="%t")){ //passage à l'opérande (ind)
		i++;
	}
	ind = atoi(instruction[i]; //enregistrement de ind
	i++;
	if (instruction[i]!=" ")&&(instruction[i]!="%t")||(instruction[i]!="%0")){
		ind = 10*ind;
		ind += atoi(instruction[i]);
		i++;
	}
	binaire = "000010%b",ind;
	binaireInt = atoi(binaire); //ça marche ? si non faire à la main :'(
	hexadecimal = "%X",binaireInt;
	return hexadecimal;
}