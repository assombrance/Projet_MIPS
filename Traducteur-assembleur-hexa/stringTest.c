#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 32

void stringTest(char* string) {

	unsigned int i = 0;
	unsigned int length = 0;
	unsigned int flag = 0;

	length = strlen(string);

	printf("\n");
	printf("********************************************************\n");
	printf("*              Welcome in String Test v1.0             *\n");
	printf("********************************************************\n");

	printf("\n");


	printf("Address : ");
	
	if (string != NULL) {
		printf("%p", string);
		printf("\n");
	} else {
		printf("Pointing to non initialized value \n");
	}
	

	printf("Length : ");
	printf("%d", length);
	printf("\n");

	printf("Presence of end token : ");
	for (i = 0; i < strlen(string) + 1; i++) {
		if (string[i] == '\0') {
			flag = 1;
		printf("%d", flag);
		} 
	}	

	printf("\n");

	
	/* Affichage de la chaîne de caractères */
	printf("String : ");
	for (i = 0; i < length; i++) {
		printf("%c", string[i]);
	}
	printf("\n\n");

	printf("See you later for another segmentation fault !\n");

	printf("\n");

}