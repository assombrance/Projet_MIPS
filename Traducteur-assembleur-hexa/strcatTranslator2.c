#include "Conversion.h"
#include "fonctionsHexa.h"

char* strcatTranslator2(char* res, char* binary, char* rs_b) {

	/* Concatène des bouts de chaîne de caractères en une seule chaîne res */
	unsigned int i, j;
	unsigned int length_binary, length_rs_b;
	unsigned int length;

	length_binary = strlen(binary);
	length_rs_b = strlen(rs_b);

	res = malloc(sizeof(*res) * length_binary + 1);

	if (res == NULL) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < length_binary; i++) {
		res[i] = binary[i];
	}
	
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

	return res;
}
