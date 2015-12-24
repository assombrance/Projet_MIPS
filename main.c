#include "binaryToHexa.h"

int main(int argc, char* argv[]) {

	char* res;

	res = malloc(sizeof(*res) + 6);

	res = binaryToHexa("11000011110000");


	return 0;
}