#include "Conversion.h"

/*************************************************************************************/
/*                            binaryToHexa v3.0                                      */
/*************************************************************************************/

/* Permet de convertir un nombre binaire quelconque en nombre hexadécimal            */

char* binaryToHexa(char* hexadecimal, char* binary) {

	/*********************************************************************************/
	/* 1) Normaliser la taille de la chaine binaire => normalizeLength               */
	/* 2) Création du masque pour isoler les grps de 4 bits => cMask                 */
	/* 3) Application du masque à la chaine de caractèhexa_converted => ET                      */
	/* 4) Reconaissance des grps de bits masqués pour conversion hexa => parsing     */
	/* 5) Faire correspondre à chaque groupe de 4 bits une valeur hexa => binaryHexa */
	/*********************************************************************************/

	unsigned int i, j;

	char* binaryTEMP = NULL;
	char* mask = NULL;
	char* binary_masked = NULL;
	char* binary_parsed = NULL;

	/* Calcul de la taille pour l'allocation mémoire de la chaîne */
	unsigned int length_binary;
	/*unsigned int length_hexa_converted;*/
	/*unsigned int r = 0;*/

	length_binary = strlen(binary);
	/*r = length_binary % HALF_BYTE;*/
/*
	if (r != 0) {
		hexa_converted = malloc(sizeof(*hexa_converted) * length_binary + (HALF_BYTE - r) + 1);
	} 
	else {
		hexa_converted = malloc(sizeof(*hexa_converted) * length_binary + 1);
	}
*/

	binaryTEMP = malloc(sizeof(*binaryTEMP) * HALF_BYTE + 1);
	mask = malloc(sizeof(*mask) * HALF_BYTE + 1);
	binary_masked = malloc(sizeof(*binary_masked) * HALF_BYTE + 1);
	binary_parsed = malloc(sizeof(*binary_parsed) * HALF_BYTE + 1);
	printf("BINARYTOHEXA : binaryTEMP => %p (après malloc)\n", binaryTEMP);
	printf("BINARYTOHEXA : mask => %p (après malloc)\n", mask);
	printf("BINARYTOHEXA : binary_masked => %p (après malloc)\n", binary_masked);
	printf("BINARYTOHEXA : binary_parsed => %p (après malloc)\n", binary_parsed);


	 /* Vérification d'allocation mémoire */
	if (( binaryTEMP == NULL) || (mask == NULL) || (binary_masked == NULL)) {
		fprintf(stderr, "Unable to allocate memory !");
		exit(EXIT_FAILURE);
	}

	/* 
	La chaine binaire est déjà normalisée en 32 bits en amont dans *Hexa.c
	hexa_converted = normalizeLength(hexa_converted, binary);

	length_hexa_converted = strlen(hexa_converted);
	*/

	/* Parcours de la chaîne de gauche à droite pour la conversion */
	/* On travaille sur un groupe de 4 bits à la fois              */
	i = 0;

	for (j = 0; j < length_binary / HALF_BYTE; j++) {

		if (j >= 1) {

		binaryTEMP = realloc(binaryTEMP, sizeof(*binaryTEMP) * (HALF_BYTE + HALF_BYTE * j) + 1);
		mask = realloc(mask, sizeof(*mask) * (HALF_BYTE + HALF_BYTE * j) + 1);
		binary_masked = realloc(binary_masked, sizeof(*binary_masked) * (HALF_BYTE + HALF_BYTE * j) + 1);
		binary_parsed = realloc(binary_parsed, sizeof(*binary_parsed) * (HALF_BYTE + HALF_BYTE * j) + 1);

			if (binaryTEMP == NULL || mask == NULL || binary_masked == NULL || binary_parsed == NULL) {
				fprintf(stderr, "Unable to allocate memory \n");
				exit(EXIT_FAILURE);
			}
		}
		
		/* Sélection des groupes de bits à masquer */
		for (i = 0; i < (HALF_BYTE + HALF_BYTE*j); i++) {

			if (binary[i] == '1') {
				binaryTEMP[i] = '1';
			}
			else {
				binaryTEMP[i] = '0';
			}
		}

		binaryTEMP[i] = '\0';

		/* Création du masque 
		char* cMask(char* stringToMask, unsigned int length_StringToMask, int offset, int nbOfOnes); */
		
		mask = cMask(mask, strlen(binaryTEMP), i + 1 - HALF_BYTE, HALF_BYTE);

		/* 3) Application du masque à la chaine de caractèhexa_converted => ET 
		char* ET(char* hexa_converted, char* binaryToApplyMask, char* mask) */

		binary_masked = ET(binary_masked, binaryTEMP, mask);
		
		/* Reconnaissance des groupes de bits masqués 
		char* parsing(char* binary_parsed, char* binary_masked) */

		binary_parsed = parsing(binary_parsed, binary_masked);	
		
		/* Génération de la chaîne résultat avec les caractèhexa_converted hexadécimaux */
		hexadecimal[j] = binaryHexa(binary_parsed);
		

	}
	hexadecimal[j] = '\0';
	
	free(binary_parsed);
	free(binary_masked);
	free(binaryTEMP);
	free(mask);

	getchar();
	stringTest(hexadecimal);

	return hexadecimal;
}
