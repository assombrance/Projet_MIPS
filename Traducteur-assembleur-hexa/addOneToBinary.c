#include "Conversion.h"

/* Permet d'ajouter 1 à une chaîne binaire */

char* addOneToBinary(char* binary) {

	/* Penser à faire une boucle à l'extérieure de la fonction si la chaîne binaire
		est de type 1111111....1111.             
		fonctionne avec searchZeros.c     

		ATTENTION on ne peut printf une chaine de caractère avec des éléments non ini
		tialisés. Sinon : "Conditional jump or move to uninitialised value(s)""  */

	char* res = NULL;
	unsigned int i = 0;
	unsigned int flag = 0;

	/*flag = searchZeros(binary);*/

	res = malloc(sizeof(*res) * strlen(binary) + flag + 1);

	if (res == NULL) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	i = strlen(binary) - 1;
	res[i + 1 + flag] = '\0'; 

	/* On détecte le premier 0 pour que la retenue ne se propage plus */
	while (binary[i] != '0') {
		
		binary[i] = '0';
		/*
		if (binary[i] == '0') {
			res[i + flag] = '1';
			carry = 0;
		} else {
			res[i + flag] = '0';
		}
		*/
		i--;
	}

	binary[i] = '1';
	/*
	if ( flag == 0) {
		while (i != -1) {
			res[i] = binary[i];
			i--;
		}
	} else {
		res[0] = '1';
	}
	*/
	
	for (i = 0; i < strlen(binary); i++) {
		res[i] = binary[i];
	}
	res[i] = '\0';

	free(binary);
	
	return res;
}
