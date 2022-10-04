// App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdlib.h>
#include <stdio.h>

#include "main.h"
#include "misc.h"

int main(int argc, char *argv[]) {
	printf("Author: %s\n\n", APP_AUTHOR);

	for (int i = 0; i < argc; i++) {
		printf("Option %02d - %s\n", i, argv[i]);
	}

	system("pause");
}
