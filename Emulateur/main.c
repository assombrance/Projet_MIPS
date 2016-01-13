#include "fonctionsHexa.h"

int main(int argv, char* argv[]){
	char* addTest1,addTest2;
	strcpy(addTest1,"add 3, 4, 5");
	printf("%s",addTest1);
	addTest2 = add(addTest1);
	printf("%s",addTest2);
}