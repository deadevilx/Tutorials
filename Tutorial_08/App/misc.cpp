
#include "misc.h"
#include <math.h>
void append(int new_value, MyNode *end, int &count) {

	while (end->next != NULL)
		end = end->next;

	end->next = new MyNode;
	end->next->prev = end;
	end->next->data = new_value;
	end->next->next = NULL;
	end = end->next;

	count++;
}

void insert(int new_value, MyNode *end , int index , int &count) {
	int k = 0;
	MyNode* new_node, * next_node;
	while ((end->next != NULL) && (k != index - 1)) {
		end = end->next;
		k++;
	}
	new_node = new MyNode;
	next_node = end->next;   // указатель на след ноду
	end->next = new_node;     // текущая нода получает *next новой ноды
	new_node->data = new_value;  // заполняем новую ноду
	new_node->next = next_node;  //
	new_node->prev = end;        //
	if (next_node != NULL) {
		next_node->prev = new_node; //след нода(если она не NULL) указывает на новую ноду
	}
	count++;
}

void del(MyNode *end,int index,int &count) {
	int k = 0;
	MyNode* next_node, * prev_node;
	while ((end->next != NULL) && (k != index)) {
		end = end->next;
		k++;
	}
	// указатель на удаляемой ноде
	prev_node = end->prev;   // указатель на пред ноду
	next_node = end->next;   // указатель на след ноду
	if (prev_node != NULL) {
		prev_node->next = end->next;  // нода перед удаляемой(если она не NULL) получает *next удаляемого
	}
	if (next_node != NULL) {
		next_node->prev = end->prev;  //нода после удаляемой(если она не NULL) получает *prev удаляемого
	}
	delete end;               // удаляем ноду
	count--;
}

void clear(MyNode *end) {
	MyNode* prev_node;
	while (end->next != NULL) {
		end = end->next;
	}
	//указатель находится на последней ноде
	while (end->prev != NULL) {
		prev_node = end->prev;    // указатель на пред ноду
		prev_node->next = NULL;   // пред нода получает в *next значение NULL
		delete end;               // удаляем текущую ноду
		end = prev_node;          // указатель становится на пред ноду
	}
}