#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "lea.h"
#include <time.h>

unsigned char k_128[16] = { 0x0f, 0x1e, 0x2d, 0x3c, 0x4b, 0x5a, 0x69, 0x78, 0x87, 0x96, 0xa5, 0xb4, 0xc3, 0xd2, 0xe1, 0xf0 };
unsigned char p[16] = { 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f };
unsigned char c[16] = { NULL };

void main() {
	unsigned int rk[144] = { NULL };
	unsigned int tmp[4] = { NULL };
	unsigned int ttmp[4] = { NULL };
	int i = 0;
	clock_t start = clock();
	while (i < 100) {
		i++;
		enc_key_schedule_128(k_128, rk);
		enc_lea_128(p, rk, c);
	}
	clock_t end = clock();

	float res1 = (float)(end - start) / CLOCKS_PER_SEC;
	printf("%lf\n", res1);
	for(int i =0; i<16; i++) printf("%02x ",c[i]);
	printf("\n");
}