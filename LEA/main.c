#include <stdio.h>
#include "lea.h"

void main() {
	int a = 0x0f0f;
	printf("%04x\n", a);
	printf("%04x\n", ROL(a, 8));
}