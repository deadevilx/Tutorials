// App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <thread>
#include <chrono>
#include <mutex>

#include "main.h"
#include "misc.h"

using std::thread;
using namespace std::chrono_literals;

struct ThreadArgument {
	int *value;
	int cycle_count;
};

int value;
std::mutex mtx;

void inc_counter(ThreadArgument *arg) {
	for (; arg->cycle_count > 0; arg->cycle_count--) {
		int tmpval = *(arg->value);
		std::this_thread::sleep_for(1ms);
		tmpval += 1;
		*(arg->value) = tmpval;
	}
}

void dec_counter(ThreadArgument *arg) {
	for (; arg->cycle_count > 0; arg->cycle_count--) {
		int tmpval = *(arg->value);
		std::this_thread::sleep_for(1ms);
		tmpval -= 1;
		*(arg->value) = tmpval;
	}
}

int main(int argc, char* argv[]) {
	thread a;
	thread b;
	thread c;
	thread d;

	ThreadArgument arg_a = {&value, 1000};
	ThreadArgument arg_b = arg_a;
	ThreadArgument arg_c = arg_a;
	ThreadArgument arg_d = arg_a;

	a = thread(inc_counter, &arg_a);
	b = thread(dec_counter, &arg_b);
	c = thread(inc_counter, &arg_c);
	d = thread(dec_counter, &arg_d);

	a.join();
	b.join();
	c.join();
	d.join();

	printf("Press any key to continue ...\n");
	int key = _getch();

	return 0;
}
