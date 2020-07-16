#include <fstream>
#include "node.h"
#include "list.h"
#include<math.h>
#include<string>
#include<iostream>
using namespace std;

bool isPresent(node* head, int x) {
	node* temp = head;
	while (temp != 0) {
		if (temp->exp == x) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}
void polyMul(node *head1, node *head2) {		//polynomial multiplication

	list result;

	node *temp = head1;			//for list 1
	node *temp2 = head2;			//for list 2
	node *temp3 = result.head;		//for resultant list

	int newExp, newCoef;

	while (temp != 0) {
		while (temp2 != 0) {
			newCoef = temp->coef*temp2->coef;
			newExp = temp->exp + temp2->exp;


			while (temp3 != 0 && temp3->exp != newExp) {
				temp3 = temp3->next;
			}
			if (temp3 != 0 && temp3->exp == newExp) {
				temp3->coef = temp3->coef + newCoef;
			}
			else if (temp3 == 0) {
				result.insert_end(newCoef, newExp);
			}
			temp2 = temp2->next;
			temp3 = result.head;
		}
		temp2 = head2;
		temp = temp->next;
	}
	cout << "	polynomial multiplication:";
	result.traverse();
	cout << endl << endl;
}
void polyAdd(node *head1, node *head2) {		//polynomial addition

	list result;

	node *temp = head1;			//for list 1
	node *temp2 = head2;			//for list 2
	node *temp4 = 0;

	int newExp, newCoef, x;

	while (temp != 0) {
		if (isPresent(head2, temp->exp)) {
			while (temp->exp != temp2->exp) {
				temp2 = temp2->next;
			}
			x = temp->coef + temp2->coef;
			result.insert_end(x, temp->exp);
		}
		else {
			result.insert_end(temp->coef, temp->exp);
		}
		temp2 = head2;
		temp = temp->next;
	}

	temp2 = head2;
	temp = head1;

	while (temp2 != 0) {
		while (temp != 0 && temp2->exp != temp->exp) {
			temp = temp->next;
		}
		if (temp == 0) {
			newExp = temp2->exp;
			newCoef = temp2->coef;

			node *temp3 = result.head;

			while (temp3 != 0 && temp3->exp > newExp) {
				temp4 = temp3;
				temp3 = temp3->next;
			}
			result.insert_after(temp4->coef, temp4->exp, newCoef, newExp);
		}
		temp2 = temp2->next;
		temp = head1;
	}
	cout << "	polynomial addition:";
	result.traverse();
	cout << endl << endl;
}
void evaluate(node *head) {		//polynomial evaluation

	node *temp = head;

	int constant = 2;
	double x = 0;
	double y = 0;
	double z = 0;
	double sum = 0;

	while (temp != 0) {
		x = temp->coef;
		y = pow(constant, temp->exp);
		z = x * y;
		sum = sum + z;

		temp = temp->next;
	}
	cout << "	poly1 after evaluation:  " << sum;
	cout << endl << endl;
}
int main() {
	cout << endl;
	list l, l2;

	std::string poly1;
	ifstream f("zobia.txt");		//open file
	if (!f) {				//if file not opened
		cout << "error" << endl;
	}
	else {
		f >> poly1;			 //read poly2
		cout << "	poly1:  " << poly1 << endl;
	}
	f.close();				//close file

	int size = poly1.size();		//to handle string subscript out of range //exception produced by 0x^0 inserted in the text file
	size = size - 4;

	for (int i = 0; i < size; i++) {
		string expp = "";
		string coeff = "";

		while (poly1[i] != 'x') {
			coeff = coeff + poly1[i];
			i++;
		}

		i = i + 2;

		while (poly1[i] != '+') {
			if (isdigit(poly1[i])) {
				expp = expp + poly1[i];
				i++;
			}
		}
		int coef = atoi(coeff.c_str());	//string to int conversion for insertion
		int exp = atoi(expp.c_str());

		l.insert_end(coef, exp);

	}

	node *head1 = l.head;

	std::string poly2;
	ifstream f1("maria.txt");		//open file

	if (!f1) {				//if file not opened
		cout << "error" << endl;
	}
	else {
		f1 >> poly2;			//read poly2
		cout << "	poly2:  " << poly2 << endl;
	}


	int size2 = poly2.size();
	size2 = size2 - 4;

	for (int i = 0; i < size2; i++) {
		string expp = "";
		string coeff = "";

		while (poly2[i] != 'x') {
			coeff = coeff + poly2[i];
			i++;
		}

		i = i + 2;

		while (poly2[i] != '+') {
			if (isdigit(poly2[i])) {
				expp = expp + poly2[i];
				i++;
			}
		}
		int coef = atoi(coeff.c_str());		//string to int conversion
		int exp = atoi(expp.c_str());

		l2.insert_end(coef, exp);
	}


	cout << endl << endl;
	node *head2 = l2.head;

	cout << "		:TASKS:		" << endl << endl;
	polyAdd(head1, head2);
	polyMul(head1, head2);
	evaluate(head2);
	system("pause");
	return 0;
}
