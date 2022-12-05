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

void print_help() {
	printf("p <pos> - print customer at <pos> index info\n");
	printf("a - append customer\n");
	printf("u <pos> - update custoper at <pos> index\n");
	printf("i <pos> - insert customer after <pos> index\n");
	printf("d <pos> - delete customer at <pos> index\n");
	printf("c - drop all database\n");
	printf("t - convert %s to %s file\n", DB_FILE_NAME, TXT_FILE_NAME);
	printf("h - print help info\n");
	printf("e or q - exit program\n");
	printf("\n");
}


int main(int argc, char *argv[]) {
	char user_query[1024] = {0};
	char user_gender[128] = {0};

	print_help();

	printf("> ");

	while (true) {
		gets_s(user_query);

		if (!strlen(user_query)) {
			printf("\n> ");

			continue;
		}

		if (user_query[0] == 'p') {
			int index = 0;

			sscanf(user_query, "%c %d", &user_query[0], &index);

			if (fs_size(DB_FILE_NAME) == 0 || fs_size(DB_FILE_NAME) / sizeof(Customer) <= index || index < 0) {
				printf("Wrong index %d, must be [0; %d]\n", index, fs_size(DB_FILE_NAME) / sizeof(Customer) - 1);
				continue;
			}

			db_print_customer(DB_FILE_NAME, index);
		} else if (user_query[0] == 'a') {
			Customer c;

			printf("\tFirst Name: ");
			scanf("%s", c.first_name);
			printf("\tLast Name: ");
			scanf("%s", c.last_name);
			printf("\tGender (male/female): ");
			scanf("%s", user_gender);
			printf("\tAccount (10 digits): ");
			scanf("%s", &c.account);
			printf("\tPhone: ");
			scanf("%s", &c.phone);

			if (!strcmp("male", user_gender)) {
				c.gender = G_MALE;
			} else if(!strcmp("female", user_gender)) {
				c.gender = G_FEMALE;
			} else {
				printf("Error: unknown gender\n");
				continue;
			}

			db_add_customer(DB_FILE_NAME, c);
		} else if (user_query[0] == 'u') {
			int index = 0;

			sscanf(user_query, "%c %d", &user_query[0], &index);

			if (fs_size(DB_FILE_NAME) == 0 || fs_size(DB_FILE_NAME) / sizeof(Customer) <= index || index < 0) {
				printf("Wrong index %d, must be [0; %d]\n", index, fs_size(DB_FILE_NAME) / sizeof(Customer) - 1);
				continue;
			}

			Customer c;

			printf("Customer #%d update:\n", index);
			printf("\tFirst Name: ");
			scanf("%s", c.first_name);
			printf("\tLast Name: ");
			scanf("%s", c.last_name);
			printf("\tGender (male/female): ");
			scanf("%s", user_gender);
			printf("\tAccount (10 digits): ");
			scanf("%d", &c.account);
			printf("\tPhone: ");
			scanf("%d", &c.phone);

			if (!strcmp("male", user_gender)) {
				c.gender = G_MALE;
			}
			else if (!strcmp("female", user_gender)) {
				c.gender = G_FEMALE;
			}
			else {
				printf("Error: unknown gender\n");
				continue;
			}

			db_upd_customer(DB_FILE_NAME, c, index);
		} else if (user_query[0] == 'i') {
			int index = 0;

			sscanf(user_query, "%c %d", &user_query[0], &index);

			if (fs_size(DB_FILE_NAME) == 0 || fs_size(DB_FILE_NAME) / sizeof(Customer) <= index || index < 0) {
				printf("Wrong index %d, must be [0; %d]\n", index, fs_size(DB_FILE_NAME) / sizeof(Customer) - 1);
				continue;
			}

			Customer c;

			printf("Customer #%d insert:\n", index);
			printf("\tFirst Name: ");
			scanf("%s", c.first_name);
			printf("\tLast Name: ");
			scanf("%s", c.last_name);
			printf("\tGender (male/female): ");
			scanf("%s", user_gender);
			printf("\tAccount (10 digits): ");
			scanf("%d", &c.account);
			printf("\tPhone: ");
			scanf("%d", &c.phone);

			if (!strcmp("male", user_gender)) {
				c.gender = G_MALE;
			}
			else if (!strcmp("female", user_gender)) {
				c.gender = G_FEMALE;
			}
			else {
				printf("Error: unknown gender\n");
				continue;
			}

			db_ins_customer(DB_FILE_NAME, c, index);
		} else if (user_query[0] == 'd') {
			int index = 0;

			sscanf(user_query, "%c %d", &user_query[0], &index);

			if (fs_size(DB_FILE_NAME) == 0 || fs_size(DB_FILE_NAME) / sizeof(Customer) <= index || index < 0) {
				printf("Wrong index %d, must be [0; %d]\n", index, fs_size(DB_FILE_NAME) / sizeof(Customer) - 1);
				continue;
			}

			db_del_customer(DB_FILE_NAME, index);
		} else if (user_query[0] == 'c') {
			db_drop(DB_FILE_NAME);
		} else if (user_query[0] == 't') {
			db_convert_to_txt(DB_FILE_NAME);
		} else if (user_query[0] == 'h') {
			print_help();
		} else if (user_query[0] == 'e' || user_query[0] == 'q') {
			break;
		} else {
			printf("Unknown command\n");
		}

		printf("\n> ");
	}

	//	printf("Press any key :)\n");
	//	int key = _getch();
}
