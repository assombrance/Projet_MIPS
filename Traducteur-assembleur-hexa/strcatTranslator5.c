#include "Conversion.h"
#include "fonctionsHexa.h"

char* strcatTranslator5(char* res, char* binary, char* rs_b, char* rt_b, char* rd_b, char* end) {

	/* Concatène des bouts de chaîne de caractères en une seule chaîne res */
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

	printf("STRCATTRANSLATOR5 : res => %p (après malloc)\n", res);

	if (res == NULL) {
		fprintf(stderr, "Unable to allocate memory \n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < length_binary; i++) {
		res[i] = binary[i];
	}
	

	length = length_binary + length_rs_b;

	res = realloc(res, sizeof(*res) * length + 1);
	printf("STRCATTRANSLATOR5 : res => %p (après 1e realloc)\n", res);
	if (res == NULL) {
		fprintf(stderr, "Unable to reallocate memory \n");
		exit(EXIT_FAILURE);
	}

	for (j = i; j < length; j++) {
		res[j] = rs_b[j - i];
	}
	

	length = length_binary + length_rs_b + length_rt_b;

	res = realloc(res, sizeof(*res) * length + 1);
	printf("STRCATTRANSLATOR5 : res => %p (après 2e realloc)\n", res);
	if (res == NULL) {
		fprintf(stderr, "Unable to reallocate memory \n");
		exit(EXIT_FAILURE);
	}

	for (k = j; k < length; k++) {
		res[k] = rt_b[k - j];
	}
	

	length = length_binary + length_rs_b + length_rt_b + length_rd_b;

	res = realloc(res, sizeof(*res) * length + 1);
	printf("STRCATTRANSLATOR5 : res => %p (après 3e realloc)\n", res);

	if (res == NULL) {
		fprintf(stderr, "Unable to reallocate memory \n");
		exit(EXIT_FAILURE);
	}
	
	for (l = k; l < length; l++) {
		res[l] = rd_b[l - k];
	}
	

	length = length_binary + length_rs_b + length_rt_b + length_rd_b + length_end;

	res = realloc(res, sizeof(*res) * length + 1);
	printf("STRCATTRANSLATOR5 : res => %p (après 4e realloc)\n", res);


	for (m = l; m < length; m++) {
		res[m] = end[m - l];
	}
	res[m] = '\0';
	
	
	return res;
}
