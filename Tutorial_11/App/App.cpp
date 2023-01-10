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
int wm;
ThreadArgument arg_a = { &value, 1000 };
ThreadArgument arg_b = arg_a;
ThreadArgument arg_c = arg_a;
ThreadArgument arg_d = arg_a;

void inc_counter(ThreadArgument *arg) {
	for (; arg->cycle_count > 0; arg->cycle_count--) {
		if (wm == 1) {
			mtx.lock();
		}
		int tmpval = *(arg->value);
		std::this_thread::sleep_for(1ms);
		tmpval += 1;
		*(arg->value) = tmpval;
		if (wm == 1) {
			mtx.unlock();
		}
	}
}

void dec_counter(ThreadArgument *arg) {
	for (; arg->cycle_count > 0; arg->cycle_count--) {
		if (wm == 1) {
			mtx.lock();
		}
		int tmpval = *(arg->value);
		std::this_thread::sleep_for(1ms);
		tmpval -= 1;
		*(arg->value) = tmpval;
		if (wm == 1) {
			mtx.unlock();
		}
	}
}

void timer_func() {
	unsigned secs = 0;
	while (true) {
		std::this_thread::sleep_for(1s);
		secs++;
		printf("sec = %d | value = %d | arg_a.count = %d | arg_b.count = %d | arg_c.count = %d | arg_d.count = %d\n", secs, value, arg_a.cycle_count, arg_b.cycle_count, arg_c.cycle_count, arg_d.cycle_count);
		if (arg_a.cycle_count == 0 && arg_b.cycle_count == 0 && arg_c.cycle_count == 0 && arg_d.cycle_count == 0) {
			printf("Value = %d\n", value);
			break;
		}
	}
}

int main(int argc, char* argv[]) {
	printf("Run program with Mutex or without? (0 - without|1 - with): ");
	scanf("%d", &wm);

	thread a;
	thread b;
	thread c;
	thread d;
	thread timer;

	a = thread(inc_counter, &arg_a);
	b = thread(dec_counter, &arg_b);
	c = thread(inc_counter, &arg_c);
	d = thread(dec_counter, &arg_d);
	timer = thread(timer_func);

	a.join();
	b.join();
	c.join();
	d.join();
	timer.join();
	printf("Press any key to continue ...\n");
	int key = _getch();

	return 0;
}
