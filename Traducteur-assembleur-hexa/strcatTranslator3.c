#include "Conversion.h"
#include "fonctionsHexa.h"

char* strcatTranslator3(char* res, char* binary, char* rs_b, char* rt_b) {

	/* Concatène des bouts de chaîne de caractères en une seule chaîne res */
	unsigned int i, j, k;
	unsigned int length_binary, length_rs_b, length_rt_b;
	unsigned int length;

	length_binary = strlen(binary);
	length_rs_b = strlen(rs_b);
	length_rt_b = strlen(rt_b);

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

	return res;
}
