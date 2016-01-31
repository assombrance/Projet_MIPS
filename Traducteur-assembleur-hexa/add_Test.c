#include "Conversion.h"


char* addHexa(char* instruction) {

	/* ATTENTION : faire une boucle si on rencontre un 0 alors il y a un segfault */

	int i=0;
	int rs,rt,rd;

	char* rs_b = NULL;
	char* rt_b = NULL;
	char* rd_b = NULL;
	
	char* binary = NULL;
	char* end = NULL;

	char* hexadecimal = NULL;

	while( (instruction[i] == ' ') || (instruction[i] == '\t') ){ /*passage au add*/
		i++;
	}
	while( (instruction[i] != ' ') && (instruction[i] != '\t') ){ /*passage de l'add*/
		i++;
	}
	while((instruction[i] == ' ') || (instruction[i] == '\t')){ /*passage à la première opérande (rd)*/
		i++;
	}
	/* atoi convertit instruction[i] (char) en entier (int)*/
	rd = atoiTranslator(instruction, i); 
	i++;

	while (isdigit(instruction[i])) {
		i++;
	}
	
	while((instruction[i]==' ')||(instruction[i]=='\t')||(instruction[i]==',')){ /*passage à la deuxième opérande (rs)*/
		i++;
	}
	rs = atoiTranslator(instruction, i); /*enregistrement de rs (décimal)*/
	i++;

	while (isdigit(instruction[i])) {
		i++;
	}
	
	while((instruction[i]==' ')||(instruction[i]=='\t')||(instruction[i]==',')){ /*passage à la troisième opérande (rt)*/
		i++;
	}
	rt = atoiTranslator(instruction, i); /*enregistrement de rt*/
	i++;
	
	printf("rs = %d || i = %d \n", rs, i);
	printf("rt = %d || i = %d \n", rt, i);
	printf("rd = %d || i = %d \n", rd, i);
	printf("\n");

	/* On considère 5 bits d'adresse de registre */
	rs_b = decimalToBinary(rs);
	for (i = 0; i < 5; i++) {
		printf("%c", rs_b[i] );
	}
	printf("\n");
	rt_b = decimalToBinary(rt);
	for (i = 0; i < 5; i++) {
		printf("%c", rt_b[i] );
	}
	printf("\n");
	rd_b = decimalToBinary(rd);
	for (i = 0; i < 5; i++) {
		printf("%c", rd_b[i] );
	}
	printf("\n");
	printf("\n");



	rs_b = normalizingLengthAddressOfRegister(rs_b);
	rt_b = normalizingLengthAddressOfRegister(rt_b);
	rd_b = normalizingLengthAddressOfRegister(rd_b);

	for (i = 0; i < 5; i++) {
		printf("%c", rs_b[i] );
	}
	printf("\n");

	for (i = 0; i < 5; i++) {
		printf("%c", rt_b[i] );
	}
	printf("\n");

	for (i = 0; i < 5; i++) {
		printf("%c", rd_b[i] );
	}
	printf("\n");


	binary = malloc(sizeof(*binary) * strlen("000000") + 1);
	end = malloc(sizeof(*end) * strlen("00000100000") + 1);

	if ((binary == NULL) || (end == NULL)) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	/* Copie la chaîne "000000" dans binaire */
	strcpy(binary, "000000");
	strcpy(end, "00000100000");

	binary = strcatAdd(binary, rs_b, rt_b, rd_b, end);

	hexadecimal = binaryToHexa(binary);

	free(binary);
	free(end);
	
	return hexadecimal;
}

char* normalizingLengthAddressOfRegister(char* rs) {

	char* res = NULL;

	unsigned int i = 0; 
	unsigned int length;
	int shift;

	length = strlen(rs);
	shift = BIT_ADDRESS_REGISTER - length;

	if (length < BIT_ADDRESS_REGISTER) {

		res = malloc(sizeof(*res) * (length + shift) + 1);
		
		if (res == NULL) {
			fprintf(stderr, "Unable to reallocate memory\n");
			exit(EXIT_FAILURE);
		}

		/* Décalage des bits de rs vers la fin de chaîne de res */
		for (i = 0; i < length; i++) {
			res[BIT_ADDRESS_REGISTER - 1 - i] = rs[length -1 - i];
		}

		/* Bourrage par des 0 pour remplir la chaîne res        */
		for (i = 0; i < shift; i++) {
			res[i] = '0';
		}

		res[BIT_ADDRESS_REGISTER] = '\0';

		free(rs);

		return res;

	} else {
		return rs;
	}

}

char* strcatAdd(char* binary, char* rs_b, char* rt_b, char* rd_b, char* end) {

	/* Concatène des bouts de chaîne de caractères en une seule chaîne res */
	char* res = NULL;
	unsigned int i, j, k, l, m;
	unsigned int length_binary, length_rs_b, length_rt_b;
	unsigned int length_rd_b, length_end;
	unsigned int length;

	length_binary = strlen(binary);
	length_rs_b = strlen(rs_b);
	length_rt_b = strlen(rt_b);
	length_rd_b = strlen(rd_b);
	length_end = strlen(end);

	res = malloc(sizeof(*res) * length_binary + 1);

	if (res == NULL) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < length_binary; i++) {
		res[i] = binary[i];
	}
	res[i] = '\0';

	length = length_binary + length_rs_b;

	res = realloc(res, sizeof(*res) * length + 1);

	if (res == NULL) {
		fprintf(stderr, "Unable to reallocate memory \n");
		exit(EXIT_FAILURE);
	}

	for (j = i; j < length; j++) {
		res[j] = rs_b[j - i];
	}
	res[j] = '\0';

	length = length_binary + length_rs_b + length_rt_b;

	res = realloc(res, sizeof(*res) * length + 1);

	if (res == NULL) {
		fprintf(stderr, "Unable to reallocate memory \n");
		exit(EXIT_FAILURE);
	}

	for (k = j; k < length; k++) {
		res[k] = rt_b[k - j];
	}
	res[k] = '\0';

	length = length_binary + length_rs_b + length_rt_b + length_rd_b;

	res = realloc(res, sizeof(*res) * length + 1);

	if (res == NULL) {
		fprintf(stderr, "Unable to reallocate memory \n");
		exit(EXIT_FAILURE);
	}
	
	for (l = k; l < length; l++) {
		res[l] = rd_b[l - k];
	}
	res[l] = '\0';

	length = length_binary + length_rs_b + length_rt_b + length_rd_b + length_end;

	res = realloc(res, sizeof(*res) * length + 1);

	for (m = l; m < length; m++) {
		res[m] = end[m - l];
	}
	res[m] = '\0';

	free(binary);
	free(rs_b);
	free(rt_b);
	free(rd_b);
	free(end);

	return res;
}

int atoiTranslator(char* instruction, int i) {

	/* Convertit instruction[i] en entier */

	unsigned signe;
	int j;
	int res = -1;

	if (instruction[i] == '-') {
		signe = -1;
	} else {
		signe = 1;
	}

	/* Saute le signe de l'opérande */
	if (instruction[i] == '+' || instruction[i] == '-') {
		i++;
	}

	/* isdigit(c) fonction de ctype.h retourne une valeur non nulle si c est un 
	chiffre, nulle sinon */
	for (j = 0; isdigit(instruction[i]); i++) {
		j = 10 * j + (instruction[i] - '0');
	}

	res = signe * j;

	return res;
}

/*****************************/
/*  Fonctions de Conversion  */
/*****************************/

char* decimalToBinary(int decimal) {

	char* res = NULL;

	if (decimal > 0) {
		res = decimalBinary(decimal);
	} 
	else {
		res = decimalBinary(decimal);
		res = invertBits(res);
		res = addOneToBinary(res);
	}

	return res;
}

/*****************************/
/* Fonctions decimalToBinary */
/*****************************/

/* Done */
int lengthBinaryToAllocate(int decimal) {

 /* Renvoi la taille de la chaîne en bits à allouer pour le décimal
	exple : lengthBinaryToAllocate(512) = 10        */

	unsigned int lengthToAllocate = 0;
	int residue = 1;
	int TEMP;

	if (decimal < 0) {
		TEMP = abs(decimal);
	} else if (decimal == 0 || decimal == 1) {
		return 1;
	} else {
		TEMP = decimal;
	}

	while (residue > 0) {
		residue = TEMP - (1 << lengthToAllocate);
		lengthToAllocate++;
	}

	return lengthToAllocate;
}
/* Done */
char* decimalBinary(int decimal) {

	/* Conversion d'un chiffre décimal en chaîne binaire
		ATTENTION : ne fonctionne pas avec des nombres négatifs */

	char* res = NULL;
	int lengthBinaryAllocated;
	unsigned int power;
	/* Problème avec les "int" compris entre -511 et 512 */
	int residue;

	lengthBinaryAllocated = lengthBinaryToAllocate(decimal);

	printf("lengthBinaryAllocated = %d\n", lengthBinaryAllocated);

	if (decimal < 0) {
		/* On rajoute 1 case pour le 0 en début de chaîne */
		res = malloc(sizeof(*res) * lengthBinaryAllocated + 1 + 1);
	} else {
		res = malloc(sizeof(*res) * lengthBinaryAllocated + 1);
	}

	if (res == NULL) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	power = lengthBinaryAllocated;

	if (decimal < 0) {
		res[0] = '0';
		while (power != 0) {
		residue = abs(decimal) - (1 << (power - 1));
	
			if (residue >= 0) {
				printf("res[%d] = %c \n", lengthBinaryAllocated - power, res[lengthBinaryAllocated - power] );
				res[lengthBinaryAllocated - (power - 1)] = '1';
				decimal = residue;
			} else {
				printf("res[%d] = %c \n", lengthBinaryAllocated - power, res[lengthBinaryAllocated - power] );
				res[lengthBinaryAllocated - (power - 1)] = '0';
			}

		power--;
		}

	res[lengthBinaryAllocated - (power - 1)] = '\0';

	} else {
		while (power != 0) {

		residue = decimal - (1 << (power - 1));
	
			if (residue >= 0) {
				res[lengthBinaryAllocated - power] = '1';
				decimal = residue;
			} else {
				res[lengthBinaryAllocated - power] = '0';
			}

		power--;
		}

	res[lengthBinaryAllocated - power] = '\0';	
	}
	
	
	return res;
}

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

char* invertBits(char* binary) {

	/* Libère la mémoire de la variable binary à la fin */

	/* Inversion des bits pour préparer le complément à deux */
	char* res = NULL;
	unsigned int i;

	res = malloc(sizeof(*res) * strlen(binary) + 1);

	for (i = 0; i < strlen(binary); i++) {
		if (binary[i] == '1') {
			res[i] = '0';
		} else {
			res[i] = '1';
		}
	}
	res[i] = '\0';

	free(binary);

	return res;
}

char* removeZero(char* binary) {

	char* res = NULL;

	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int length;

	length = strlen(binary);

	/*Parcours de la chaîne jusqu'au premier 1*/
	while (binary[i] != '1') {
		i++;
	}

	res = malloc(sizeof(*res) * (strlen(binary) - i) + 1);

	/*Retournement de la chaîne de caractères*/
	for (i = 0; i < length; i++) {
		res[j] = binary[i];
		j++;
	}
	res[j] = '\0';
	
	free(binary);

	return res;
}

char* normalizeLength(char* binary_normalized, char* binary) {

	unsigned int length;
	unsigned int r, offset;
	unsigned int i, j;

	length = strlen(binary);
	r = length % HALF_BYTE;
	offset = HALF_BYTE - r;

	if (r != 0) {
		/*
		binary_normalized = malloc(sizeof(*binary_normalized) * SIZE_MAX); (length + offset + 1));*/

		for (i = offset; i < length + offset; i++) {
			binary_normalized[i] = binary[i - offset];
		}
		binary_normalized[i] = '\0';

		for (j = 0; j < offset; j++) {
			binary_normalized[j] = '0';
		}

	}
	else {
		return binary;
	}
	
	return binary_normalized;
}

char* parsing(char* binary_parsed, char* binary_masked) {

	unsigned int i = 0;
	unsigned j = 0;
	unsigned k;
	unsigned int flag = 0;
	unsigned int offset = 0;
	unsigned int length_binaryMasked;
	int buffer = 0;
	char* nullString = NULL;

	/* La fonction strlen ne prend pas en compte le caractère de fin de chaine dans son renvoi */
	nullString = malloc(sizeof(*nullString) * strlen(binary_masked) + 1);
	
	length_binaryMasked = strlen(binary_masked);

	for (k = 0; k < length_binaryMasked; k++) {
		nullString[k] = '0';
	}
	nullString[k] = '\0';

	if (strcmp(binary_masked, nullString) != 0) {

		while (!flag) {

			if (binary_masked[i] == '0') {

				for (j = offset; j < offset + HALF_BYTE; j++) {
					if (binary_masked[j] == '1') { /* sinon il considère le caractère ASCII donc 48 pour '0'...*/
						buffer += 1;
					}
					binary_parsed[j - offset] = binary_masked[j];
				}

				binary_parsed[j - offset] = '\0';

				if (buffer != 0) {
					flag = 1;
				}
				else {
					buffer = 0;
				}
			}
			else {
				for (j = offset; j < offset + HALF_BYTE; j++) {
					binary_parsed[j - offset*j] = binary_masked[j];
				}
				binary_parsed[j - offset] = '\0';
				flag = 1;
			}

			i++;
			offset += HALF_BYTE;
		}
	}
	else {
		for (k = 0; k < HALF_BYTE; k++) {
			binary_parsed[k] = '0';
		}
		binary_parsed[k] = '\0';
	}

	free(nullString);
	
	return binary_parsed;
}

char* ET(char* res, char* binaryToApplyMask, char* mask) {

	/* Malloc de la taille de la chaine mask */
	unsigned int i;

	for (i = 0; i < strlen(mask); i++) {
		res[i] = binaryToApplyMask[i] & mask[i];
	}
	res[i] = '\0';

	return res;
}

char* cMask(char* mask, unsigned int length_StringToBeMasked, int offset, int nbOfOnes) {

	unsigned int i;

	/* Dans le malloc on rajoute 1 pour le caractère de fin de chaîne 
	mask = malloc(sizeof(*mask) * (length_StringToBeMasked + 1));
	*/
	i = 0;

	/* Création d'une chaîne de 0 */
	while (i < length_StringToBeMasked) {
		mask[i] = '0';
		i++;
	}
	mask[i] = '\0';

	/* Ajout des "1" dans la chaîne de "0" */
	for (i = offset - 1; i < (offset - 1) + nbOfOnes; i++) {
		mask[i] = '1';

	}

	return mask;
}

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
	unsigned int length_res;
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

char binaryHexa(char* binary_parsed) {

	char resHexa;

	if (strcmp(binary_parsed, "0000") == 0) {
		resHexa = '0';
	}
	else if (strcmp(binary_parsed, "0001") == 0) {
		resHexa = '1';
	}
	else if (strcmp(binary_parsed, "0010") == 0) {
		resHexa = '2';
	}
	else if (strcmp(binary_parsed, "0011") == 0) {
		resHexa = '3';
	}
	else if (strcmp(binary_parsed, "0100") == 0) {
		resHexa = '4';
	}
	else if (strcmp(binary_parsed, "0101") == 0) {
		resHexa = '5';
	}
	else if (strcmp(binary_parsed, "0110") == 0) {
		resHexa = '6';
	}
	else if (strcmp(binary_parsed, "0111") == 0) {
		resHexa = '7';
	}
	else if (strcmp(binary_parsed, "1000") == 0) {
		resHexa = '8';
	}
	else if (strcmp(binary_parsed, "1001") == 0) {
		resHexa = '9';
	}
	else if (strcmp(binary_parsed, "1010") == 0) {
		resHexa = 'A';
	}
	else if (strcmp(binary_parsed, "1011") == 0) {
		resHexa = 'B';
	}
	else if (strcmp(binary_parsed, "1100") == 0) {
		resHexa = 'C';
	}
	else if (strcmp(binary_parsed, "1101") == 0) {
		resHexa = 'D';
	}
	else if (strcmp(binary_parsed, "1110") == 0) {
		resHexa = 'E';
	}
	else {
		resHexa = 'F';
	}

	return resHexa;
}
