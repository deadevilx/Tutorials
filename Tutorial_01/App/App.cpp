// App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "main.h"
#include "misc.h"

void example_01() {
	unsigned char u_char = 255;		// value range 0..255
	char s_char = u_char / 2;		// value range -128..127

	printf("u_char variable size is %d bytes, value range %u..%u\n", sizeof(u_char), 0, u_char);
	printf("s_char variable size is %d bytes, value range %d..%d\n", sizeof(s_char), -s_char - 1, s_char);
}

void example_02() {
	unsigned int u_int = 4294967295;
	int s_int = u_int / 2;

	printf("u_int variable size is %d bytes, value range %u..%u\n", sizeof(u_int), 0, u_int);
	printf("s_int variable size is %d bytes, value range %d..%d\n", sizeof(s_int), -s_int - 1, s_int);
}

void example_03() {
	unsigned long long int ull_int = 18446744073709551615;
	long long int sll_int = ull_int / 2;

	printf("ull_int variable size is %d bytes, value range %llu..%llu\n", sizeof(ull_int), 0ULL, ull_int);
	printf("sll_int variable size is %d bytes, value range %lld..%lld\n", sizeof(sll_int), -sll_int - 1, sll_int);
}

void example_04() {
	double dp_pi = acos(-1);
	float sp_pi = dp_pi;

	printf("dp_pi variable size is %d bytes, value is %.21lf\n", sizeof(dp_pi), dp_pi);
	printf("sp_pi variable size is %d bytes, value is %.6f\n", sizeof(sp_pi), sp_pi);
}

void hometask_01() {
	unsigned short us_int = 65535;		// value range 0..65535
}

int main(int argc, char *argv[]) {
	printf("Running example_01:\n");
	example_01();

	printf("\n\nRunning hometask_01:\n");
	hometask_01();

	printf("\n\nRunning example_02:\n");
	example_02();

	printf("\n\nRunning example_03:\n");
	example_03();

	printf("\n\nRunning example_04:\n");
	example_04();

	system("pause");
}
