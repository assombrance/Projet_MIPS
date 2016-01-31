#include "fonctionsHexa.h"
#include "Conversion.h"

#include "fonctionsHexa.h"
#include "Conversion.h"

/* ATTENTION free dans la main avec nop.c */

char* nopHexa(char* res, char* instruction) {

	unsigned int i = 0;
	char* NOP = res;

	for (i = 0; i < x86; i++) {
		NOP[i] = '0';
	}
	NOP[i] = '\0';

	return NOP;
}