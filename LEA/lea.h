#pragma once
#include <stdio.h>
#include <string.h>

#define k_len 128

#if k_len == 128
#define nk 16
#elif k_len == 192
#define nr 28
#define nk 24
#else
#define nr 32
#define nk 32

#endif

void enc_lea(unsigned char* c, unsigned char* p, unsigned int* rk, unsigned int len);
void dec_lea(unsigned char* p, unsigned char* c, unsigned int* rk, unsigned int len);
void round_enc(unsigned int* y, unsigned int* x, unsigned int* rk, unsigned int i);
void round_dec(unsigned int* y, unsigned int* x, unsigned int* rk, unsigned int i);
void enc_key_schedule(unsigned char* k, unsigned int* rk, unsigned int len);
void dec_key_schedule(unsigned char* k, unsigned int* rk, unsigned int len);