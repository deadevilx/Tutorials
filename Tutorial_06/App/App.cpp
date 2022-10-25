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


#define STACK_OVERFLOW
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

		srand(time(NULL)); // ≥н≥ц≥ал≥зац≥€ генератора випадкових чисел

		for (int i = 0; i < array_sz; i++) {
			array[i] = rand() % 1000 / 10.0;
		}
		

		// створи в файл≥ misc.cpp функц≥ю "... rms(..., ...)", €ка приймаЇ першим аргументом масив array, другим к≥льк≥сть елемент≥в в ньому
		// ≥ вертаЇ —≈–≈ƒЌ№ќ ¬јƒ–ј“»„Ќ≈ ¬≤ƒ’»Ћ≈ЌЌя типу double
		// визви њњ тут ≥ роздрукуй елементи масиву ≥, окремо, њх середньоквадратичне в≥дхиленн€

		printf("\n\n≈лементи массиву :\n");

		for (int i = 0; i < array_sz; i++) {
			printf("% lf\n", array[i]);
		}
		double skv = rms(array, array_sz);

		printf("\n—≈–≈ƒЌ№ќ ¬јƒ–ј“»„Ќ≈ ¬≤ƒ’»Ћ≈ЌЌя: \n%lf\n", skv);

		delete[] array; // чистим за собою
	} while (array_sz != 0);

	//	printf("Ќатисн≥ть будь-€ку кн€палку :)\n");
	//	int key = _getch();
}
