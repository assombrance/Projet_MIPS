#include "compileFromText.h"
#include "Conversion.h"

int main(int argc, char* argv[]) {

	/* Conversion de chaine binaire => chaine hexadécimale*/
	/*
	char* res;

	res = malloc(sizeof(*res) + 6);

	res = binaryToHexa("1101001");
	*/

	/*test de la fonction de conversion decimal => binaire*/
	printf("Décalage de %d à gauche : %d \n", 0, 1 << 0);
	printf("Décalage de %d à gauche : %d \n", 1, 1 << 1);
	printf("Décalage de %d à gauche : %d \n", 2, 1 << 2);
	printf("Décalage de %d à gauche : %d \n", 3, 1 << 3);
	printf("Décalage de %d à gauche : %d \n", 4, 1 << 4);
	printf("Décalage de %d à gauche : %d \n", 5, 1 << 5);
	printf("Décalage de %d à gauche : %d \n", 6, 1 << 6);


	decimalToBinary(17);

	return 0;
}