#pragma once
#include "lea.h"

unsigned int delta[8] = { 0xc3efe9db, 0x44626b02, 0x79e27c8a, 0x78df30ec, 0x715ea49e, 0xc785da0a, 0xe04ef22a, 0xe5c40957
};
void enc_lea_128(unsigned char* p, unsigned int* rk,unsigned char* c) {
	unsigned int x[4] = { NULL };
	unsigned int tmp[4] = { NULL };

	memcpy(x, p, 16);
	for (int i = 0; i < nr; i++) {
		round_enc_128(x, rk+(6*i),i,tmp);
		memcpy(x, tmp,16);
	}
	memcpy(c, x, 16);
}

void dec_lea_128(unsigned int* c, unsigned int* rk, unsigned int* p) {
	unsigned int x[4] = { NULL };
	unsigned int tmp[4] = { NULL };

	memcpy(x, c, 4);
	for (int i = 0; i < nr; i++) {
		round_dec_128(x, rk, i, tmp);
		memcpy(x, tmp, 4);
	}
	memcpy(c, x, 4);
}


unsigned int ROL(unsigned int x, unsigned int i) {
	return (x<<i) | (x>>(32-i));
}

unsigned int ROR(unsigned int x, unsigned int i) {
	return (x >> i) | (x << (32 - i));
}

void round_enc_128(unsigned int* x, unsigned int* rk, unsigned int i, unsigned int* y) {
	*(y) = ROL(((*x) ^ (*rk)) + (*(x + 1) ^ *(rk + 1)),9);
	*(y + 1) = ROR((*(x + 1) ^ *(rk + 2)) + ((*(x + 2) ^ *(rk + 3))),5);
	*(y + 2) = ROR((*(x + 2) ^ *(rk + 4)) + ((*(x + 3) ^ *(rk + 5))),3);
	*(y + 3) = *x;
}

void round_dec_128(unsigned int* x, unsigned int* rk, unsigned int i, unsigned int* y) {
	*(y) = *(x + 3);
	*(y + 1) = (ROR(*x, 9) - (*(y) ^ *rk)) ^ *(rk + 1);
	*(y + 2) = (ROL(*(x + 1), 5) - *(y + 1) ^ *(rk + 2)) ^ *(rk + 3);
	*(y + 3) = (ROL(*(x + 2), 3) - *(y + 2) ^ *(rk + 4)) ^ *(rk + 5);
}


void enc_key_schedule_128(unsigned char* k, unsigned int* rk) {
	unsigned int T[4] = { NULL };
	memcpy(T, k, 16);
	for (unsigned int i = 0; i < 24; i++) {
		T[0] = ROL((T[0] + ROL(delta[i % 4], i)), 1);
		T[1] = ROL((T[1] + ROL(delta[i % 4], i + 1)), 3);
		T[2] = ROL((T[2] + ROL(delta[i % 4], i + 2)), 6);
		T[3] = ROL((T[3] + ROL(delta[i % 4], i + 3)), 11);
		*(rk + (i*6)+0) = T[0];
		*(rk + (i * 6) + 1) = T[1];
		*(rk + (i * 6) + 2) = T[2];
		*(rk + (i * 6) + 3) = T[1];
		*(rk + (i * 6) + 4) = T[3];
		*(rk + (i * 6) + 5) = T[1];
	}
}

void dec_key_schedule_128(unsigned char* k, unsigned int* rk) {
	unsigned int T[4] = { NULL };
	memcpy(T, k, 16);
	for (int i = 0; i < 24; i++) {
		T[0] = ROL(T[0] + ROL(delta[i % 4], i), 1);
		T[1] = ROL(T[1] + ROL(delta[i % 4], i + 1), 3);
		T[2] = ROL(T[2] + ROL(delta[i % 4], i + 2), 6);
		T[3] = ROL(T[3] + ROL(delta[i % 4], i + 3), 11);
		*(rk + 27 - (i * 6) + 0) = T[0];
		*(rk + 27 - (i * 6) + 1) = T[1];
		*(rk + 27 - (i * 6) + 2) = T[2];
		*(rk + 27 - (i * 6) + 3) = T[3];
		*(rk + 27 - (i * 6) + 4) = T[4];
		*(rk + 27 - (i * 6) + 5) = T[5];
	}
}



