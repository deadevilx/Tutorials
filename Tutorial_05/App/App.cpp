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

		srand(time(NULL)); // ініціалізація генератора випадкових чисел

		for (int i = 0; i < array_sz; i++) {
			// Тут заповни інші параметри конуса як-то array[i].base.center.x і т.д.
			array[i].base.center_x = 0;
			array[i].base.center_y = 0;
			array[i].base.radius = rand() % 1000 / 10.0;
			array[i].height = rand() % 1000 / 10.0;
			double r = array[i].base.radius;
			double h = array[i].height;
			double _PI = acos(-1);
			double s = _PI * pow(r, 2);
			double v = s * h/ 3;
			
			printf("Радіус %lf\n", r);
			printf("Висота %lf\n", h);
			printf("Площа основи %lf\n", s);
			printf("Об'єм %lf\n", v);
			printf("---------------------\n");
		}

		// А тут красиво роздрукуй ВСІ параметри всіх конусів, а також площу основ і обєми
	

		delete[] array; // чистим за собою
	} while (array_sz != 0);

//	printf("Натисніть будь-яку княпалку :)\n");
//	int key = _getch();
}
