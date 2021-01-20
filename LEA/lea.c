#include <stdio.h>
#include "lea.h"
#include "Basic Operation.h"


//void enc_lea_128(char* p, int* rk, char* c) {
//	char* x = NULL;
//	char* tmp = NULL;
//	x = (char*)calloc(16, sizeof(char));
//	tmp = (char*)calloc(16, sizeof(char));
//
//	memcpy(x, p, 16);
//	for (int i = 0; i < nr; i++) {
//		round_enc(x, rk,i,tmp);
//		memcpy(x, tmp,16);
//	}
//	memcpy(c, x, 16);
//
//	free(x);
//	free(tmp);
//}

int ROL(int x, int i) {
	int tmp = x;
	return ((x << i) | (tmp >> (32 - i)));
}

//void round_enc(char* x, int* rk,int i, char* y) {
//	x[i+1] = left_rot()
//}

