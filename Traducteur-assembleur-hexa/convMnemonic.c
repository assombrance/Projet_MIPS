#include "fonctionsHexa.h"
#include "Conversion.h"


char* convMnemonic(char* res, char* mnemonic, char* ligne) {

	char* mnemonic_conv = mnemonic;

	unsigned int i = 0;
	unsigned int maxMnemo = 0;
	unsigned int length = 0;


	do {
		i++;
	} while (ligne[i] != ' ');

	mnemonic_conv = realloc(mnemonic, sizeof(*mnemonic) * i + 1); 

	printf("CONVMNEMONIC : mnemonic_conv => %p (après malloc) \n", mnemonic_conv );
	printf("CONVMNEMONIC : res => %p (après malloc) \n", res );
	maxMnemo = i;

	for (i = 0; i < maxMnemo; i++) {
		mnemonic_conv[i] = ligne[i];
	}
	mnemonic_conv[i] = '\0';

	length = strlen(mnemonic_conv);
	printf(" length : %d\n", length );


	switch (length) {
		
		case 1 :

		if (strcmpTranslator(mnemonic_conv, "j")) {
			res = jHexa(res, ligne);
		} else {
			printf("Mnémonique non reconnue.\n");
			exit(EXIT_FAILURE);
		}

		break;

		case 2 :

			if (strcmpTranslator(mnemonic_conv, "or")) {
				res = orHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "lw")) {
				res = lwHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "sw")) {
				res = swHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "jr")) {
				res = jrHexa(res, ligne);
			} else {
				printf("Mnémonique non reconnue.\n");
				exit(EXIT_FAILURE);
			}

		break;
	
		case 3 :

		if (length == 3) {
			if (strcmpTranslator(mnemonic_conv,"add")) {
				res = addHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "sub")) {
				res = subHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "div")) {
				res = divHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "and")) {
				res = andHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "xor")) {
				res = xorHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "sll")) {
				res = sllHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "srl")) {
				res = srlHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "slt")) {
				res = sltHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "lui")) {
				res = luiHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "beq")) {
				res = beqHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "bne")) {
				res = bneHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "jal")) {
				res = jalHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "nop")) {
				res = nopHexa(res, ligne);
			} else {
				printf(" Mnémonique non reconnue.\n");
				exit(EXIT_FAILURE);
			}		
			}
			
		break;

		case 4 :

			if (strcmpTranslator(mnemonic_conv, "addi")) {
				res = addiHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "mult")) {
				res = multHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "rotr")) {
				res = rotrHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "mfhi")) {
				res = mfhiHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "mflo")) {
				res = mfloHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "bgtz")) {
				res = bgtzHexa(res, ligne);
			} else if (strcmpTranslator(mnemonic_conv, "blez")) {
				res = blezHexa(res, ligne);
			} else {
				printf("Mnémonique non reconnue.\n");
				exit(EXIT_FAILURE);
			}

		break;

		case 7 :

			if (strcmpTranslator(mnemonic_conv, "syscall")) {
				res = syscallHexa(res, ligne);
			} else {
				printf("Mnémonique non reconnue.\n");
				exit(EXIT_FAILURE);
			}

		default :

			printf("Unknown mnemonic \n");
			exit(EXIT_FAILURE);

		break;
	}
	

	/* return res; */
	return res;
	
}
