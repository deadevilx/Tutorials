// App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

#include "main.h"
#include "misc.h"

void example_01() {
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;

	printf("������ ����� A = ");
	scanf("%lf", &a);
	printf("������ ����� B = ");
	scanf("%lf", &b);

	c = a * b;
	printf("a * b = %lf\n", c);
	c = a / b;
	printf("a / b = %lf\n", c);
	c = pow(a, b);
	printf("a ^ b = %lf\n", c);

	if (a == b) {
		printf("a = b\n");
	} else if (a < b) {
		printf("a < b\n");
	} else {
		printf("a > b\n");
	}
}

void hometask_01() {
	/*
		�� ��������������� ��������

		� ����� 26 ����� ����� �������� C = A � ������ B
		������� �� � ���� ��� ����� ����� A i B �� �������������� ������� pow
	*/

	int a = 0; // ���� ���� ������, ���� ��� ��'���� ���� �����
	int b = 0; // ���� ���� ������, ���� ��� ��'���� ���� �����

	printf("\n================================================================\n\n");
	printf("������ ����� A = ");
	scanf("%d", &a);
	printf("������ ����� B = ");
	scanf("%d", &b);

	// ������ B �� ������� 0 ������� A ���� �� ����. ��������� �������� � A. B ������� ���� �������� �� 1

	/* �� � Tutorial_00 ����� ���� ����:
	for (int i = ����; i > ������; i = i - 1) {
		���� ������
	}

	³� ���������� �����
	int i = ����;
	while (i > ������) {
		���� ������

		i = i - 1;
	}

	�� ��� ���� � ������ ������� � ������������
	*/

	// ��� �²� ����
	int i = a;
	while ((b - 1) > 0) {
		a = a * i;
		b = b - 1;
	}

	printf("a ^ b = %d\n", a);
}

int main(int argc, char *argv[]) {
	system("chcp 1251"); // Cyrillic symbols support

	example_01();

	hometask_01();

	printf("�������� ����-��� �������� :)\n");
	int key = _getch();
}
