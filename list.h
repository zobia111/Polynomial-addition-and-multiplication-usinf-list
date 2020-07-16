#pragma once
#include "node.h"
#include<string>
using std::string;

class list {
public:
	node * head;

	list();
	bool isEmpty();
	void insert_end(int, int);
	void insert_after(int, int, int, int);
	void delete_node(int, int);
	void traverse();
};
