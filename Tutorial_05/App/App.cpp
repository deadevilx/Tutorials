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

		Cone *array = new Cone[array_sz];

		srand(time(NULL)); // ����������� ���������� ���������� �����

		for (int i = 0; i < array_sz; i++) {
			// ��� ������� ���� ��������� ������ ��-�� array[i].base.center.x � �.�.

			array[i].height = rand() % 1000 / 10.0;
		}

		// � ��� ������� ��������� �Ѳ ��������� ��� ������, � ����� ����� ����� � ����
		double _PI = acos(-1);

		delete[] array; // ������ �� �����
	} while (array_sz != 0);

//	printf("�������� ����-��� �������� :)\n");
//	int key = _getch();
}
