
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
	str_1 = strcat(str_1, str_2);
	return str_1;
}

std::string concat_strings(std::string str_1, std::string str_2) {
	return  str_1 + str_2;
	//return str_1;
}

int find_cstrings(char *str_1, char *str_2) {
	int pos = 0;
	pos = strstr(str_1, str_2) - &str_1[0];
	printf("%c %c %d\n", str_1[0], str_1[5], &str_1[5] - &str_1[0]);
	return pos;
	
}

int find_strings(std::string str_1, std::string str_2) {
	int pos = 0;
	pos = str_1.find(str_2);
	return pos;
}
