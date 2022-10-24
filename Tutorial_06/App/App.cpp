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

		srand(time(NULL)); // ініціалізація генератора випадкових чисел

		for (int i = 0; i < array_sz; i++) {
			array[i] = rand() % 1000 / 10.0;
		}

		// створи в файлі misc.cpp функцію "... rms(..., ...)", яка приймає першим аргументом масив array, другим кількість елементів в ньому
		// і вертає СЕРЕДНЬОКВАДРАТИЧНЕ ВІДХИЛЕННЯ типу double
		// визви її тут і роздрукуй елементи масиву і, окремо, їх середньоквадратичне відхилення

		delete[] array; // чистим за собою
	} while (array_sz != 0);

	//	printf("Натисніть будь-яку княпалку :)\n");
	//	int key = _getch();
}
