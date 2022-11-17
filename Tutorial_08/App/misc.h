#ifndef _MISC_H
#define _MISC_H

#include <cstring>
#include <string>

struct MyNode {
	MyNode *prev;
	int data;
	MyNode *next;
};

void append(int new_value, MyNode* end, int& count);
void insert(int new_value, MyNode* end, int index, int& count);
void del(MyNode* end, int index, int& count);
void clear(MyNode* end);
#endif
