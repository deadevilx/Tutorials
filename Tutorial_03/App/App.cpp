// App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <string.h>

#include "main.h"
#include "misc.h"

#define FG_RED			"\x1b[91m"
#define FG_GREEN		"\x1b[92m"
#define FG_YELLOW		"\x1b[93m"
#define FG_BLUE			"\x1b[94m"
#define FG_MAGENTA		"\x1b[95m"
#define FG_CYAN			"\x1b[96m"
#define FG_WHITE		"\x1b[97m"

void print_help() {
	printf("Commands:\n");
	printf("    color\n");
	printf("        1 - red\n");
	printf("        2 - green\n");
	printf("        3 - yellow\n");
	printf("        4 - blue\n");
	printf("        5 - magenta\n");
	printf("        6 - cyan\n");
	printf("        7 - white\n");
	printf("\n");
	printf("    help - print this help\n");
	printf("    exit or quit - terminate program\n");
}

void conditions_and_cycles() {
	char cmd[128] = {0};

	do {
		gets_s(cmd);
		if (!strcmp("color", cmd)) {
			int clr_code = 0;
			printf("enter color code: ");
			scanf("%d", &clr_code);
			switch(clr_code) {
			case 1:
				printf(FG_RED);
				break;
			case 2:
				printf(FG_GREEN);
				break;
			case 3:
				break;
			default:
				if (clr_code == 5) {
					printf(FG_MAGENTA);
				} else if (clr_code == 6) {
				} else {
					printf("Unknown color code\n");
				}
			}
		} else if (!strcmp("help", cmd)) {
			print_help();
		}
	} while (strcmp("quit", cmd) && strcmp("exit", cmd));
}

int main(int argc, char *argv[]) {
	system("chcp 1251"); // Cyrillic symbols support

	print_help();

	conditions_and_cycles();

//	printf("Натисніть будь-яку княпалку :)\n");
//	int key = _getch();
}
