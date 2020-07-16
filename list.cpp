#include "list.h"
#include "node.h"
#include<iostream>
#include<string>
using namespace std;

list::list() {			//constructor
	head = 0;
}

bool list::isEmpty() {	//check for empty
	if (head == 0)
		return 1;
	else
		return 0;
}
void list::traverse() {	//display the list
	node *temp = head;
	while (temp != 0) {
		cout << "	" << temp->coef << "x" << "^" << temp->exp << "+";
		temp = temp->next;
	}
	cout << "  0";
}


void list::insert_end(int coef, int exp) {	//insert new node at the end of list

	node *p = new node;		//create a node
	p->coef = coef;
	p->exp = exp;
	p->next = 0;

	node *temp = head;		//temporary pointer

	if (isEmpty()) {				//check for empty list
		head = p;
	}

	else {
		while (temp->next != 0) {		//insert at the end
			temp = temp->next;
		}
		temp->next = p;
	}
}

void list::insert_after(int oldCoef, int oldExp, int coef, int exp) {

	if (isEmpty()) {
		std::cout << "empty" << std::endl;
		exit(0);
	}
	node *temp = head;
	while (temp->coef != oldCoef && temp->exp != oldExp && temp != 0) {
		temp = temp->next;
	}
	if (temp == 0) {
		cout << "cannot find required node" << endl;
		exit(0);
	}
	else {
		node *p = new node;
		p->coef = coef;
		p->exp = exp;


		p->next = temp->next;
		temp->next = p;
	}
}

void list::delete_node(int coef, int exp) {
	node *p, *temp;
	p = 0;
	temp = head;
	if (isEmpty()) {
		cout << "empty";
		exit(0);
	}
	while (temp->coef != coef && temp->exp != exp && temp != 0) {
		p = temp;
		temp = temp->next;
	}

	if (temp == 0) {
		cout << "empty";
		exit(0);

	}
	if (p == 0) {
		head = temp->next;
	}

	else {
		p->next = temp->next;
		delete temp;
	}
}
