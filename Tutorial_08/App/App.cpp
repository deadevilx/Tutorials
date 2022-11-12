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
	printf("a - append element\n");
	printf("i - insert element\n");
	printf("d - delete element\n");
	printf("c - clear list\n");
	printf("e or q - exit program\n");
	printf("\n");
}

int main(int argc, char* argv[]) {
	MyNode list = {NULL, 0, NULL};
	int *array_a = NULL;
	int *array_b = NULL;
	int array_sz = 3;
	char cmd[1024] = {0};

	print_help();

	array_a = (int *)malloc(array_sz * sizeof(int));
	array_b = new int[array_sz];

	srand(time(NULL));
	for (int i = 0; i < array_sz; i++) {
		*(array_a + i) = rand() % 100;
		array_b[i] = rand() % 100;
	}

	printf("Array A:\n\t");
	for (int i = 0; i < array_sz; i++) {
		printf("% 4d", *(array_a + i));
	}
	printf("\n");

	printf("Array B:\n\t");
	for (int i = 0; i < array_sz; i++) {
		printf("% 4d", array_b[i]);
	}
	printf("\n");

	MyNode *end = &list;

	while (end->next != NULL)
		end = end->next;

	for (int i = 0; i < array_sz; i++) {
		(*end).next = new MyNode;
		(*(*end).next).prev = end;
		(*(*end).next).data = array_a[i];
		(*(*end).next).next = NULL;
		end = (*end).next;
	}

	for (int i = 0; i < array_sz; i++) {
		end->next = new MyNode;
		end->next->prev = end;
		end->next->data = array_b[i];
		end->next->next = NULL;
		end = end->next;
	}

	printf("Array A + B:\n\t");
	end = &list;
	int count = 0;                              // счетчик размера list

	while (end->next != NULL) {
		end = end->next;
		count++;
		printf("% 4d", end->data);

	}
	printf("\n");
	



	while (true) {
		printf("Size of list:  %d\n", count);
		gets_s(cmd);

		if (cmd[0] == 'a') {
			int new_value;
			sscanf(cmd, "%c %d", &cmd[0], &new_value);

			MyNode *end = &list;

			while (end->next != NULL)
				end = end->next;

			end->next = new MyNode;
			end->next->prev = end;
			end->next->data = new_value;
			end->next->next = NULL;
			end = end->next;


		}
		else if (cmd[0] == 'i') {
			int index, k = 0;
			int new_value;
			MyNode* temp, * p_node;
			sscanf(cmd, "%c %d %d", &cmd[0], &index, &new_value);

			MyNode* end = &list;

			if (index < 0 || index > count) {
				printf("WRONG INDEX! Enter index from 0 to %d\n", count);
			}
			else {
				while ((end->next != NULL) && (k != index)) {
					end = end->next;
					k++;
				}

				temp = new MyNode;
				p_node = end->next;   // указатель на след ноду
				end->next = temp;     // предыдущий узел указывает на новый узел
				temp->data = new_value;  // заполняем новый узел
				temp->next = p_node;
				temp->prev = end;
				if (p_node != NULL) {
					p_node->prev = temp; //след нода указивает на новый узел
				}
				count++;
			}
		}
				
		  else if (cmd[0] == 'c') {

			MyNode* end = &list;

			while (end->next != NULL) {
				end = end->next;
			}

			while (end->prev != NULL) {
				MyNode* prev = end->prev;
				end->prev->next = NULL;
				delete end;
				end = prev;
			}
		}
		  else if (cmd[0] == 'e' || cmd[0] == 'q') {
			break;
		} else {
			printf("Unknown command\n");
		}

		printf("Array A + B:\n\t");
		end = &list;
		while (end->next != NULL) {
			end = end->next;
			printf("% 4d", end->data);

		}
		printf("\n");
	}

	free(array_a);
	delete[] array_b;

	while (end->next != NULL) {
		end = end->next;
	}

	while (end->prev != NULL) {
		MyNode *prev = end->prev;
		end->prev->next = NULL;
		delete end;
		end = prev;
	}


	//	printf("Press any key :)\n");
	//	int key = _getch();
}
