
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
	next_node = end->next;   // ��������� �� ���� ����
	end->next = new_node;     // ������� ���� �������� *next ����� ����
	new_node->data = new_value;  // ��������� ����� ����
	new_node->next = next_node;  //
	new_node->prev = end;        //
	if (next_node != NULL) {
		next_node->prev = new_node; //���� ����(���� ��� �� NULL) ��������� �� ����� ����
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
	// ��������� �� ��������� ����
	prev_node = end->prev;   // ��������� �� ���� ����
	next_node = end->next;   // ��������� �� ���� ����
	if (prev_node != NULL) {
		prev_node->next = end->next;  // ���� ����� ���������(���� ��� �� NULL) �������� *next ����������
	}
	if (next_node != NULL) {
		next_node->prev = end->prev;  //���� ����� ���������(���� ��� �� NULL) �������� *prev ����������
	}
	delete end;               // ������� ����
	count--;
}

void clear(MyNode *end) {
	MyNode* prev_node;
	while (end->next != NULL) {
		end = end->next;
	}
	//��������� ��������� �� ��������� ����
	while (end->prev != NULL) {
		prev_node = end->prev;    // ��������� �� ���� ����
		prev_node->next = NULL;   // ���� ���� �������� � *next �������� NULL
		delete end;               // ������� ������� ����
		end = prev_node;          // ��������� ���������� �� ���� ����
	}
}