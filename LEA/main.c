#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "lea.h"
#include <time.h>
#include <stdlib.h>
#include "padding.h"
#include "mode_of_operation.h"

unsigned char k[32] = { 0x0f, 0x1e, 0x2d, 0x3c, 0x4b, 0x5a, 0x69, 0x78, 0x87, 0x96, 0xa5, 
0xb4, 0xc3, 0xd2, 0xe1, 0xf0, 0xf0, 0xe1 , 0xd2 , 0xc3 , 0xb4,  0xa5, 0x96, 0x87, 0x78, 0x69, 0x5a,
0x4b, 0x3c, 0x2d, 0x1e, 0x0f };
unsigned char p_128[16] = { 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f };
unsigned char p_192[16] = { 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f };
unsigned char p_256[16] = { 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f };
unsigned char c[16] = { 0x00, };

void main() {
	unsigned int rk[192] = { 0x00, };
	unsigned int tmp[4] = { 0x00, };
	unsigned int ttmp[4] = { 0x00, };


	printf("****************LEA-128 TEST****************\n");

	enc_key_schedule(k, rk, 128);
	enc_lea(c, p_128, rk,128);

	printf("Plain Text : ");
	for (int i = 0; i < 16; i++) printf("%02x ", p_128[i]);
	printf("\n");

	printf("Cipher Text : ");
	for(int i =0; i<16; i++) printf("%02x ",c[i]);
	printf("\n");

	//dec_key_schedule(k, rk, 128);
	dec_lea(p_128, c, rk, 128);
	printf("Plain Text : ");
	for (int i = 0; i < 16; i++) printf("%02x ", p_128[i]);

	printf("\n");
	printf("\n");
	printf("\n");

	printf("****************LEA-192 TEST****************\n");
	enc_key_schedule(k, rk, 192);
	enc_lea(c, p_192, rk, 192);

	printf("Plain Text : ");
	for (int i = 0; i < 16; i++) printf("%02x ", p_192[i]);
	printf("\n");

	printf("Cipher Text : ");
	for (int i = 0; i < 16; i++) printf("%02x ", c[i]);
	printf("\n");

	//dec_key_schedule(k, rk, 192);
	dec_lea(p_192, c, rk, 192);
	printf("Plain Text : ");
	for (int i = 0; i < 16; i++) printf("%02x ", p_192[i]);
	printf("\n");
	printf("\n");
	printf("\n");

	printf("****************LEA-256 TEST****************\n");
	enc_key_schedule(k, rk, 256);
	enc_lea(c, p_256, rk, 256);

	printf("Plain Text : ");
	for (int i = 0; i < 16; i++) printf("%02x ", p_256[i]);
	printf("\n");

	printf("Cipher Text : ");
	for (int i = 0; i < 16; i++) printf("%02x ", c[i]);
	printf("\n");


	//dec_key_schedule(k, rk, 256);
	dec_lea(p_256, c, rk, 256 );
	printf("Plain Text : ");
	for (int i = 0; i < 16; i++) printf("%02x ", p_256[i]);
	printf("\n");

	unsigned int length = 0; 
	unsigned int rem = 0;
	length = sizeof(p_192)/16;
	unsigned char* out;
	out = calloc(16 * (length + 1), sizeof(p_192[0]));
	enc_key_schedule(k, rk, 192);
	rem = sizeof(p_192) % 16;
	enc_ecb_lea(out, p_192, rk, length, rem);
	dec_ecb_lea(p_192, out, rk, length);
	/*printf("%d\n", length);
	unsigned char* out;
	memcpy(out, p_192, sizeof(p_192));
	out[sizeof(p_192)] = 0x80;
	for (int i = 0; i < 16*(length+1); i++) printf("%02x ", out[i]);
	printf("\n");



	unsigned char temp[16] = { 0x00, };
	unsigned char* c_out = NULL;
	c_out = calloc(16 * (length + 1), sizeof(p_192));
	for (int i = 0; i < length + 1; i++) {
		enc_lea(temp, out+(16*i), rk, 192);
		memcpy(c_out+(16*i), temp, 16);
	}
	for (int i = 0; i < 16 * (length + 1); i++) printf("%02x ", c_out[i]);
	printf("\n");*/

	free(out);

}