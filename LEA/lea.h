#pragma once
#include <stdio.h>
#include <string.h>

#define k_len 128

#if k_len == 128
#define nr 24
#define nk 16
#elif k_len == 192
#define nr 28
#define nk 24
#else
#define nr 32
#define nk 32

#endif



void enc_lea_128(unsigned char* p, unsigned int* rk, unsigned char* c);
void dec_lea_128(unsigned int* c, unsigned int* rk, unsigned int* p);
unsigned int ROL(unsigned int x, unsigned int i);
unsigned int ROR(unsigned int x, unsigned int i);
void round_enc_128(unsigned int* x, unsigned int* rk, unsigned int i, unsigned int* y);
void round_dec_128(unsigned int* x, unsigned int* rk, unsigned int i, unsigned int* y);
void enc_key_schedule_128(unsigned char* k, unsigned int* rk);
void dec_key_schedule_128(unsigned char* k, unsigned int* rk);