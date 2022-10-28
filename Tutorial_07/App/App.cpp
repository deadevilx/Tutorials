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
	char str_1[1024];
	char str_2[1024];

	while (true) {
		printf("Enter 1-st string or empty one to exit: ");
		gets_s(str_1);

		if (strlen(str_1) == 0)
			break;

		printf("Enter 2-nd string: ");
		gets_s(str_2);

		echo_cstring(str_1);
		echo_string(str_2);

		printf("1-st + 2-nd = %s\n", concat_cstrings(str_1, str_2));
		printf("1-st + 2-nd = %s\n", concat_strings(str_1, str_2).c_str());

		printf("2-nd in 1-st pos = %d\n", find_cstrings(str_1, str_2));
		printf("2-nd in 1-st pos = %d\n", find_strings(str_1, str_2));
	}

	//	printf("Press any key :)\n");
	//	int key = _getch();
}
