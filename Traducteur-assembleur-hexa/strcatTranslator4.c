#include "Conversion.h"
#include "fonctionsHexa.h"

char* strcatTranslator4(char* res, char* binary, char* rs_b, char* rt_b, char* rd_b) {

	/* Concatène des bouts de chaîne de caractères en une seule chaîne res */
	unsigned int i, j, k, l;
	unsigned int length_binary, length_rs_b, length_rt_b;
	unsigned int length_rd_b;
	unsigned int length;

	length_binary = strlen(binary);
	length_rs_b = strlen(rs_b);
	length_rt_b = strlen(rt_b);
	length_rd_b = strlen(rd_b);

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

	return res;
}
