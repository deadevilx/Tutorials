
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
		sum += array[i];                                 // ����� ��� ��������
	}
	double sr_arif = sum / size_of_array;               // ������ ����������� ��������
	for (int i = 0; i < size_of_array; i++) {
		array[i] = (array[i] - sr_arif) * (array[i] - sr_arif);  // ������� ������ ������� �������� � ���������� ������������� 
	}
	double sum_kv = 0;
	for (int i = 0; i < size_of_array; i++) {
		sum_kv += array[i];                           // ����� ��������
	}
	double dispersiya = sum_kv / size_of_array;     //��������
	double skv = sqrt(dispersiya);                  //������������������� ���������
	return skv;
}   
