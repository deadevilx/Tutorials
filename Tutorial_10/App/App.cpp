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
	printf("w - donate <pos1> employee month bonus to <pos2> employee\n", TXT_FILE_NAME);
	printf("h - print help info\n");
	printf("e or q - exit program\n");
	printf("\n");
}


int main(int argc, char *argv[]) {
	char user_query[1024] = {0};
	char strbuf_abc[128] = {0};
	int ibuf = 0;
	unsigned ubuf = 0;

	db_load();

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
			} else if (index >= persons.size() || index < 0) {
				printf("Wrong index %d, must be [0; %d]\n", index, persons.size() - 1);
				continue;
			}

			persons[index]->showInfo();
		} else if (user_query[0] == 'a') {
			printf("Person type (%d - Customer, %d - Employee): ", P_CUSTOMER, P_EMPLOYEE);
			scanf("%d", &ibuf);

			if (ibuf == P_CUSTOMER) {
				Person *p = new Customer();

				printf("\tFirst Name: ");
				scanf("%s", strbuf_abc);
				p->setFirstName(strbuf_abc);

				printf("\tLast Name: ");
				scanf("%s", strbuf_abc);
				p->setLastName(strbuf_abc);

				printf("\tGender (male/female): ");
				scanf("%s", strbuf_abc);
				if (!strcmp("male", strbuf_abc)) {
					p->setGender(G_MALE);
				} else if(!strcmp("female", strbuf_abc)) {
					p->setGender(G_FEMALE);
				} else {
					printf("Error: unknown gender\n");
					continue;
				}

				printf("\tAccount (10 digits): ");
				scanf("%d", &ibuf);
				((Customer *)p)->setAccount(ibuf);

				printf("\tPhone: ");
				scanf("%d", &ibuf);
				((Customer *)p)->setPhone(ibuf);

				persons.push_back(p);
			} else if (ibuf == P_EMPLOYEE) {
				Person *p = new Employee();


				persons.push_back(p);
			} else {
			}
		} else if (user_query[0] == 'u') {
		} else if (user_query[0] == 'i') {
		} else if (user_query[0] == 'd') {
		} else if (user_query[0] == 'c') {
			persons.clear();
		} else if (user_query[0] == 't') {
			db_save_txt();
		} else if (user_query[0] == 'h') {
			print_help();
		} else if (user_query[0] == 'e' || user_query[0] == 'q') {
			break;
		} else {
			printf("Unknown command\n");
		}

		printf("\n> ");
	}

	db_save();

	for (int i = 0; i < persons.size(); i++) {
		delete persons[i];
	}

	//	printf("Press any key :)\n");
	//	int key = _getch();
}
