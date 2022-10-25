
#include "misc.h"
#include <math.h>

unsigned long long n_sum(unsigned long long n) {
	unsigned long long total = 0;
	for (unsigned long long i = 0; i <= n; i++) {
		total += i;	
	}
	return total;
	//if (n > 1)
	//	return n + n_sum(n - 1);
	//else
	//	return n;
}

double rms(double array[], int size_of_array) {
	double sum = 0;
	for (int i = 0; i < size_of_array; i++) {   
		sum += array[i];                                 // Сумма всіх елементів
	}
	double sr_arif = sum / size_of_array;               // Середнє арифметичне елементів
	for (int i = 0; i < size_of_array; i++) {
		array[i] = (array[i] - sr_arif) * (array[i] - sr_arif);  // Квадрат різниці кожного елемента і середнього арифметичного 
	}
	double sum_kv = 0;
	for (int i = 0; i < size_of_array; i++) {
		sum_kv += array[i];                           // Сумма квадратів
	}
	double dispersiya = sum_kv / size_of_array;     //Дисперсія
	double skv = sqrt(dispersiya);                  //Середньоквадратичне відхилення
	return skv;
}   
