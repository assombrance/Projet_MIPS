#include "binaryToHexa.h"
#include "compileFromText.h"

int main(int argc, char* argv[]) {

	/* Conversion de chaine binaire => chaine hexadécimale*/
	/*
	char* res;

	res = malloc(sizeof(*res) + 6);

	res = binaryToHexa("1101001");
	*/

	/*Ouverture du fichier d'instructions */
	tokenizingSource("InstructionsMIPS.txt");

	return 0;
}