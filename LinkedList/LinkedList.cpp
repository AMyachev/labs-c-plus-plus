#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;
class person {
	string fname;
	string sname;
public:
	void show() { cout << sname << " " << fname << endl; }
	person(string fn, string sn) {
		fname = fn;
		sname = sn;
	}
	person(){}
	void change(string fn, string sn) {
		fname = fn;
		sname = sn;
	}
	string getName() {
		return fname;
	}
};
LinkedList<int> *list;
LinkedList<person> *user_list;
bool complexity = false;
void menu();
void show_list() {
	system("cls");
	if (!complexity) {
		for (int i = 0; i < list->get_size(); i++) {
			cout << i + 1 << ") " << *((*list)[i]) << "\n";
		}
	}
	else {
		for (int i = 0; i < user_list->get_size(); i++) {
			cout << i + 1 << ") ";
			(*user_list)[i]->show();
		}
	}
}
void Add() {
	system("cls");
	cout << "Choose option:\n1)Insert in the end\n2)Insert in position\n3)Back to menu\nDecision: ";
	int decision;
	cin >> decision;
	if (!complexity) {
		if (list == nullptr)list = new LinkedList<int>();
		cout << "Enter nomber: ";
		int value;
		cin >> value;
		switch (decision) {
		case 1: {
			list->push(&value);
			menu();
		}
		case 2: {
			show_list();
			cout << "Enter position from 1 to " << list->get_size()<<": ";
			int position;
			cin >> position;
			list->insert(position - 1, &value);
			menu();
		}
		case 3:menu();
		}
	}
	else {
		if (user_list == nullptr)user_list = new LinkedList<person>();
		cout << "Enter first name: ";
		string fname;
		cin >> fname;
		cout << "Enter second name: ";
		string sname;
		cin >> sname;
		person* value = new person(fname, sname);
		switch (decision) {
		case 1: {
			user_list->push(value);
			menu();
		}
		case 2: {
			show_list();
			cout << "Enter position from 1 to " << user_list->get_size()<<": ";
			int position;
			cin >> position;
			user_list->insert(position - 1, value);
			menu();
		}
		case 3:menu();
		}
	}
}
void deleting() {
	system("cls");
	show_list();
	cout << endl << "Chose nomber of element to delete: ";
	int decision;
	cin >> decision;
	if (!complexity)list->erase(decision-1);
	else user_list->erase(decision-1);
}
void Editing() {
	system("cls");
	show_list();
	cout << "Chose element to edit: ";
	int decision;
	cin >> decision;
	if (complexity) {
		if (user_list->get_size() == 0)return;
		string a, b;
		person* elem = (*user_list)[decision];
		cout << "Enter new first name: ";
		cin >> a;
		cout << "Enter new second name: ";
		cin >> b;
		elem->change(a, b);
	}
	else {
		if (list->get_size() == 0)return;
		cout << "Enter new value: ";
		int value;
		cin >> value;
		int* elem = (*list)[decision];
		*elem = value;
	}
}
void menu() {
	system("cls");
	cout << "1)Show list\n2)Add element\n3)Delete element\n4)Delete list\n5)Choose list\n6)Edit element\n7)Exit\nChoose option: ";
	int decision;
	cin >> decision;
	switch (decision) {
	case 1: {
		show_list();
		system("pause");
		menu();
	}
	case 2: {
		Add();
	}
	case 3: {
		deleting();
		menu();
	}
	case 4: {
		if (!complexity)delete(list);
		else if (user_list != nullptr)delete(user_list);
		menu();
	}
	case 5: {
		cout << "Choose option: 1)standart type 2)user type\nDecision: ";
		int decision;
		cin >> decision;
		if (decision == 2)complexity = true;
		else complexity = false;
		menu();
	}
	case 6: {
		Editing();
		menu();
	}
	case 7: {
		exit(1);
	}
	}
}
int main()
{
	cout << "Choose option: 1)standart type 2)user type\nDecision: ";
	int decision;
	cin >> decision;
	if (decision == 2)complexity = true;
	list = new LinkedList<int>();
	user_list = new LinkedList<person>();
	menu();
}
