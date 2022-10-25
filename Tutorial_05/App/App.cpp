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
			array[i].base.center_x = 0;
			array[i].base.center_y = 0;
			array[i].base.radius = rand() % 1000 / 10.0;
			array[i].height = rand() % 1000 / 10.0;
			double r = array[i].base.radius;
			double h = array[i].height;
			double _PI = acos(-1);
			double s = _PI * pow(r, 2);
			double v = s * h/ 3;
			
			printf("����� %lf\n", r);
			printf("������ %lf\n", h);
			printf("����� ������ %lf\n", s);
			printf("��'�� %lf\n", v);
			printf("---------------------\n");
		}

		// � ��� ������� ��������� �Ѳ ��������� ��� ������, � ����� ����� ����� � ����
	

		delete[] array; // ������ �� �����
	} while (array_sz != 0);

//	printf("�������� ����-��� �������� :)\n");
//	int key = _getch();
}
