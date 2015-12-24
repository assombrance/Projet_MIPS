#include "binaryToHexa.h"

int main(int argc, char* argv[]) {

	char* res;

	res = malloc(sizeof(*res) + 6);

	res = binaryToHexa("10010010");


	return 0;
}