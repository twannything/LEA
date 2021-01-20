#pragma once

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


int ROL(char x, int i);