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

		int *array = new int[array_sz]; // створюємо масив з array_sz, кожен з яких є цілим числом

		srand(time(NULL)); // ініціалізація генератора випадкових чисел

		for (int i = 0; i < array_sz; i++) {
			array[i] = rand() % 2000 - 1000; // зповнюємо i-тий елемент масиву випадковими числами в діапазоні [-1000; 1000)
		}

		printf("\nUnsorted array:");
		for (int i = 0; i < array_sz; i++) {
			printf(" %d", array[i]);
		}

		float fl_array[4] { 3.5, 3.1, -100, -99.999 };

		// ЗРОБИ, ЩОБ ЕЛЕМЕНТИ В МАСИВІ БУЛИ РОЗТАШОВАНІ ЗА ЗРОСТАННЯМ
		for (int i = 0; i < array_sz; i++) {
			for (int j = 0; j < array_sz - i - 1; j++) {
				// тут, якщо j + 1-ший елемент масиву менше попереднього, то міняєш їх місцями
				if (array[j + 1] < array[j]) {
					int n = array[j];
					array[j] = array[j + 1];
					array[j + 1] = n;
				}
				// робиться це так
				// додаткова змінна = j-тий елемент масиву
				// j-тий елемент масиву = j + 1-ший елемент масиву
				// j + 1-ший елемент масиву = додаткова змінна
			}
		}

		printf("\n\nSorted array:");
		for (int i = 0; i < array_sz; i++) {
			printf(" %d", array[i]);
		}

		delete[] array; // чистим за собою
	} while (array_sz != 0);

//	printf("Натисніть будь-яку княпалку :)\n");
//	int key = _getch();
}
