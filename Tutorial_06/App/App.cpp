// App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#include "main.h"
#include "misc.h"

//#define STACK_OVERFLOW
#ifdef STACK_OVERFLOW
#define N_DEPTH			4096
#else
#define N_DEPTH			5
#endif

int main(int argc, char* argv[]) {
	system("chcp 1251"); // Cyrillic symbols support

	unsigned long long n = N_DEPTH;
	printf("0..%llu sum is %llu\n", n, n_sum(n));

	int array_sz = 0;

	do {
		printf("\n\nEnter array size or 0 to exit: ");
		scanf("%d", &array_sz);

		double *array = new double[array_sz];

		srand(time(NULL)); // ����������� ���������� ���������� �����

		for (int i = 0; i < array_sz; i++) {
			array[i] = rand() % 1000 / 10.0;
		}

		// ������ � ���� misc.cpp ������� "... rms(..., ...)", ��� ������ ������ ���������� ����� array, ������ ������� �������� � �����
		// � ����� ������������������� ²�������� ���� double
		// ����� �� ��� � ��������� �������� ������ �, ������, �� ������������������� ���������

		delete[] array; // ������ �� �����
	} while (array_sz != 0);

	//	printf("�������� ����-��� �������� :)\n");
	//	int key = _getch();
}
