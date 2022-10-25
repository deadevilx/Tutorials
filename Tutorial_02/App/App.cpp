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

	printf("Введіть число A = ");
	scanf("%lf", &a);
	printf("Введіть число B = ");
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
		Це багатостроковий коментар

		В рядку 26 цього файлу значення C = A в степені B
		Зробити те ж саме для цілих чисел A i B не використовуючи функцію pow
	*/

	int a = 0; // може бути додатнє, нуль або від'ємне ціле число
	int b = 0; // може бути додатнє, нуль або від'ємне ціле число

	printf("\n================================================================\n\n");
	printf("Введіть число A = ");
	scanf("%d", &a);
	printf("Введіть число B = ");
	scanf("%d", &b);

	// допоки B не дорівнює 0 множимо A саме на себе. Результат зберігаємо в A. B кожного разу зменшуємо на 1

	/* ти в Tutorial_00 бачив цикл типу:
	for (int i = щось; i > чогось; i = i - 1) {
		щось робимо
	}

	Він аналогічний циклу
	int i = щось;
	while (i > чогось) {
		щось робимо

		i = i - 1;
	}

	от цей цикл в даному завданні і використовуй
	*/

	// ТУТ ТВІЙ ЦИКЛ
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

	printf("Натисніть будь-яку княпалку :)\n");
	int key = _getch();
}
