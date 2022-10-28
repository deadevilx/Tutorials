
#include "misc.h"
#include <math.h>

void echo_cstring(char *str) {
	for (int i = 0; i < strlen(str); i++) {
		printf("%c", str[i]);
	}
	printf("\n");
}

void echo_string(std::string str) {
	for (int i = 0; i < str.length(); i++) {
		printf("%c", str[i]);
	}
	printf("\n");
}

char *concat_cstrings(char *str_1, char *str_2) {
	return str_1;
}

std::string concat_strings(std::string str_1, std::string str_2) {
	return str_1;
}

int find_cstrings(char *str_1, char *str_2) {
	int pos = 0;
	return pos;
}

int find_strings(std::string str_1, std::string str_2) {
	int pos = 0;
	return pos;
}
