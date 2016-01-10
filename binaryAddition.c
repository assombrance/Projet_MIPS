#include "Conversion.h"

char* binaryAddition(char* binary_1) {

	/*Fonctionne uniquement  pour un addition avec 1*/
	unsigned int i = 0;
	unsigned int length_1, length_2;
	unsigned int length;
	char* res;
	unsigned int carry = 1;

	res = malloc(sizeof(*res) + 32);
	/*
	length_1 = strlen(binary_1);
	length_2 = strlen(binary_2);
	
	if (length_1 - length_2 > 0) {
		binary_2 = Conversion_equalizingLength(binary_1, binary_2);
	}
	*/

	length = strlen(binary_1);
	/*Tentative de généralisation
	for (i = 0; i < length; i++) {
		if (binary_1[i] == '1' && binary_2[i] == '1') {
			res[i] = '0';
			if ()
		}
		else if (binary_1[i] == '0' && binary_2 == '0') {
			res[i] = '0'
		}
		else {

		}
		*/
		
	while ((binary_1[length - (i + 1)] == '1') && (carry == 1)) {
		binary_1[length - (i + 1)] = '0';
		carry = 1;
		i++;
	}
	binary_1[length - (i + 1)] = '1';
	carry = 0;

	return binary_1;

}