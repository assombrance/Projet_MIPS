#include "Conversion.h"

/*************************************************************************************/
/*                            binaryToHexa v3.0                                      */
/*************************************************************************************/

/* Permet de convertir un nombre binaire quelconque en nombre hexadécimal            */

char* binaryToHexa(char* binary) {

	/*********************************************************************************/
	/* 1) Normaliser la taille de la chaine binaire => normalizeLength               */
	/* 2) Création du masque pour isoler les grps de 4 bits => cMask                 */
	/* 3) Application du masque à la chaine de caractères => ET                      */
	/* 4) Reconaissance des grps de bits masqués pour conversion hexa => parsing     */
	/* 5) Faire correspondre à chaque groupe de 4 bits une valeur hexa => binaryHexa */
	/*********************************************************************************/

	unsigned int i, j; /*k*/
	char* res = NULL;
	char* binaryTEMP = NULL;
	char* mask = NULL;
	char* binary_masked = NULL;
	char* binary_parsed = NULL;

	/* Calcul de la taille pour l'allocation mémoire de la chaîne */
	unsigned int length_binary;
	unsigned int r = 0;

	length_binary = strlen(binary);
	r = length_binary % HALF_BYTE;

	if (r != 0) {
		res = malloc(sizeof(*res) * length_binary + (HALF_BYTE - r) + 1);
	} 
	else {
		res = malloc(sizeof(*res) * length_binary + 1);
	}

	binaryTEMP = malloc(sizeof(*binaryTEMP) * HALF_BYTE + 1);
	mask = malloc(sizeof(*mask) * HALF_BYTE + 1);
	binary_masked = malloc(sizeof(*binary_masked) * HALF_BYTE + 1);
	binary_parsed = malloc(sizeof(*binary_parsed) * HALF_BYTE + 1);

	 /* Vérification d'allocation mémoire */
	if (res == NULL) {
		fprintf(stderr, "Unable to allocate memory !");
		exit(EXIT_FAILURE);
	}

	if (binaryTEMP == NULL || mask == NULL || binary_masked == NULL) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	/* 
	1) Normaliser la taille de la chaine binaire => normalizeLength 
	char* normalizeLength(char* binary_normalized, char* binary);
	*/
	res = normalizeLength(res, binary);

	unsigned int length_res;
	length_res = strlen(res);

	/* Parcours de la chaîne de gauche à droite pour la conversion */
	/* On travaille sur un groupe de 4 bits à la fois              */
	i = 0;

	for (j = 0; j < length_res / HALF_BYTE; j++) {

		if (j >= 1) {
		binaryTEMP = realloc(binaryTEMP, sizeof(*binaryTEMP) * (HALF_BYTE + HALF_BYTE * j) + 1);
		mask = realloc(mask, sizeof(*mask) * (HALF_BYTE + HALF_BYTE * j) + 1);
		binary_masked = realloc(binary_masked, sizeof(*binary_masked) * (HALF_BYTE + HALF_BYTE * j) + 1);
		binary_parsed = realloc(binary_parsed, sizeof(*binary_parsed) * (HALF_BYTE + HALF_BYTE * j) + 1);
		}
		
		if (binaryTEMP == NULL || mask == NULL || binary_masked == NULL || binary_parsed == NULL) {
			fprintf(stderr, "Unable to allocate memory \n");
			exit(EXIT_FAILURE);
		}

		/* Sélection des groupes de bits à masquer */
		for (i = 0; i < (HALF_BYTE + HALF_BYTE*j); i++) {

			if (res[i] == '1') {
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

		/* 3) Application du masque à la chaine de caractères => ET 
		char* ET(char* res, char* binaryToApplyMask, char* mask) */

		binary_masked = ET(binary_masked, binaryTEMP, mask);

		/* Reconnaissance des groupes de bits masqués 
		char* parsing(char* binary_parsed, char* binary_masked) */

		binary_parsed = parsing(binary_parsed, binary_masked);			

		/* Génération de la chaîne résultat avec les caractères hexadécimaux */
		res[j] = binaryHexa(binary_parsed);
		res[j + 1] = '\0';

	}

	free(binary_parsed);
	free(binary_masked);
	free(binaryTEMP);
	free(mask);

	return res;
}
