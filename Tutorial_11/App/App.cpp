// App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <thread>

#include "main.h"
#include "misc.h"

using std::thread;

struct ThreadArgument {
	int *value;
	int cycle_count;
};

int value;

void inc_counter(ThreadArgument *arg) {
	for (int i = 0; i < arg->cycle_count; i++) {
		*(arg->value) += 1;
	}
}

void dec_counter(ThreadArgument *arg) {
	for (int i = 0; i < arg->cycle_count; i++) {
		*(arg->value) -= 1;
	}
}

int main(int argc, char* argv[]) {
	thread a;
	thread b;
	thread c;
	thread d;

	ThreadArgument arg = {&::value, 1000000};

	a = thread(inc_counter, &arg);
	b = thread(dec_counter, &arg);
	c = thread(inc_counter, &arg);
	d = thread(dec_counter, &arg);

	a.join();
	b.join();
	c.join();
	d.join();

	printf("Press any key to continue ...\n");
	int key = _getch();

	return 0;
}
