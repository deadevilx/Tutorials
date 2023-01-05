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
	printf("p <pos> - print person info at <pos> index\n");
	printf("a - append person\n");
	printf("u <pos> - update person at <pos> index\n");
	printf("i <pos> - insert person at <pos> index\n");
	printf("d <pos> - delete person at <pos> index\n");
	printf("c - drop all database\n");
	printf("t - generate %s file\n", TXT_FILE_NAME);
	printf("h - print help info\n");
	printf("e or q - exit program\n");
	printf("\n");
}


int main(int argc, char* argv[]) {
	char user_query[1024] = { 0 };
	char strbuf_abc[128] = { 0 };
	char strbuf_role[128] = { 0 };
	int ibuf = 0;
	unsigned ubuf = 0;

	db_load(DB_FILE_NAME);

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

			if (persons.empty()) {
				printf("Persons database is empty!\n");
				printf("\n> ");
				continue;
			}
			else if (index >= persons.size() || index < 0) {
				printf("Wrong index %d, must be [0; %d]\n", index, persons.size() - 1);
				continue;
			}

			persons[index]->showInfo();
		}
		else if (user_query[0] == 'a') {
			persons.push_back(add_person());
	    }
		else if (user_query[0] == 'u') {
			int index = 0;

			sscanf(user_query, "%c %d", &user_query[0], &index);

			if (persons.empty()) {
				printf("Persons database is empty!\n");
				printf("\n> ");
				continue;
			}
			else if (index >= persons.size() || index < 0) {
				printf("Wrong index %d, must be [0; %d]\n", index, persons.size() - 1);
				continue;
			}
			persons.erase(persons.begin() + index);
			persons.insert(persons.begin() + index, add_person());
		}
		else if (user_query[0] == 'i') {
			int index = 0;

			sscanf(user_query, "%c %d", &user_query[0], &index);

			if (persons.empty()) {
				printf("Persons database is empty!\n");
				printf("\n> ");
				continue;
			}
			else if (index >= persons.size() || index < 0) {
				printf("Wrong index %d, must be [0; %d]\n", index, persons.size() - 1);
				continue;
			}
			persons.insert(persons.begin()+index, add_person());
		
		}
		else if (user_query[0] == 'd') {
			int index = 0;

			sscanf(user_query, "%c %d", &user_query[0], &index);

			if (persons.empty()) {
				printf("Persons database is empty!\n");
				printf("\n> ");
				continue;
			}
			else if (index >= persons.size() || index < 0) {
				printf("Wrong index %d, must be [0; %d]\n", index, persons.size() - 1);
				continue;
			}
			persons.erase(persons.begin() + index);
		}
		else if (user_query[0] == 'c') {
			for (int i = 0; i < persons.size(); i++) {
				delete persons[i];
			}
			persons.clear();
		}
		else if (user_query[0] == 't') {
			db_save_txt();
		}
		else if (user_query[0] == 'h') {
			print_help();
		}
		else if (user_query[0] == 'e' || user_query[0] == 'q') {
			break;
		}
			else {
				printf("Unknown command\n");
			}

			printf("\n> ");
		}

		db_save();

		for (int i = 0; i < persons.size(); i++) {
			delete persons[i];
		}
		persons.clear();

		//	printf("Press any key :)\n");
		//	int key = _getch();
	}
