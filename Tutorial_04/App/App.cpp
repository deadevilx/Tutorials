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

int main(int argc, char *argv[]) {
	system("chcp 1251"); // Cyrillic symbols support

	int array_sz = 0;

	do {
		printf("\n\nEnter array size or 0 to exit: ");
		scanf("%d", &array_sz);

		int *array = new int[array_sz]; // ��������� ����� � array_sz, ����� � ���� � ����� ������

		srand(time(NULL)); // ����������� ���������� ���������� �����

		for (int i = 0; i < array_sz; i++) {
			array[i] = rand() % 2000 - 1000; // ��������� i-��� ������� ������ ����������� ������� � ������� [-1000; 1000)
		}

		printf("\nUnsorted array:");
		for (int i = 0; i < array_sz; i++) {
			printf(" %d", array[i]);
		}

		float fl_array[4] { 3.5, 3.1, -100, -99.999 };

		// �����, ��� �������� � ����² ���� ���������Ͳ �� ����������
		for (int i = 0; i < array_sz; i++) {
			for (int j = 0; j < array_sz - i - 1; j++) {
				// ���, ���� j + 1-��� ������� ������ ����� ������������, �� ����� �� ������
				if (array[j + 1] < array[j]) {
					int n = array[j];
					array[j] = array[j + 1];
					array[j + 1] = n;
				}
				// �������� �� ���
				// ��������� ����� = j-��� ������� ������
				// j-��� ������� ������ = j + 1-��� ������� ������
				// j + 1-��� ������� ������ = ��������� �����
			}
		}

		printf("\n\nSorted array:");
		for (int i = 0; i < array_sz; i++) {
			printf(" %d", array[i]);
		}

		delete[] array; // ������ �� �����
	} while (array_sz != 0);

//	printf("�������� ����-��� �������� :)\n");
//	int key = _getch();
}
