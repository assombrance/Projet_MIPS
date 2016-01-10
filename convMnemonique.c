#include "compileFromText.h"

#define MAX_SIZE 4

void convMnemo(char* ligne) {

	int pointeur = 0; //pointeur pour lire la ligne
	int i = 0, resultat;
	char* operation[MAX_SIZE];


	if (operation == "ADD") {
		resultat = add(ligne);
	}
	else if (operation == "ADDI") {
		resultat = addi(ligne);
	}
	else if (operation == "SUB") {
		resultat = sub(ligne);
	}
	else if (operation == "MULT") {
		resultat = mult(ligne);
	}
	else if (operation == "DIV") {
		resultat = mult(ligne);
	}
	else if (operation == "AND") {
		resultat = and (ligne);
	}
	else if (operation == "OR") {
		resultat = or (ligne);
	}
	else if (operation == "XOR") {
		resultat = xor (ligne);
	}
	else if (operation == "ROTR") {
		resultat = rotr(ligne);
	}
	else if (operation == "SLL") {
		resultat = sll(ligne);
	}
	else if (operation == "SRL") {
		resultat = srl(ligne);
	}
	else if (operation == "SLT") {
		resultat = slt(ligne);
	}
	else if (operation == "LW") {
		resultat = lw(ligne);
	}
	else if (operation == "SW") {
		resultat = sw(ligne);
	}
	else if (operation == "LUI") {
		resultat = lui(ligne);
	}
	else if (operation == "MFHI") {
		resultat = mfhi(ligne);
	}
	else if (operation == "MFLO") {
		resultat = mflo(ligne);
	}
	else if (operation == "BEQ") {
		resultat = beq(ligne);
	}
	else if (operation == "BNE") {
		resultat = bne(ligne);
	}
	else if (operation == "BGTZ") {
		resultat = bgtz(ligne);
	}
	else if (operation == "BLEZ") {
		resultat = blez(ligne);
	}
	else if (operation == "J") {
		resultat = j(ligne);
	}
	else if (operation == "JAL") {
		resultat = jal(ligne);
	}
	else if (operation == "JR") {
		resultat = jr(ligne);
	}
	else {
		fprintf(stderr, "Mn�monique non reconnue \n");
		exit(EXIT_FAILURE);
	}

}