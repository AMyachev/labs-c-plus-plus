#include "pch.h"
#include <iostream>
#include "ciclestack.h"
#include <string>
using namespace std;
class IndexOutOfRange : public std::exception {
public:
	const char* what() const noexcept {
		return "Index out of range\n";
	}
};
struct Mystruct
{
	string name;
	int a;
	int b;
	
};
class train {
	//конструктор присваивания 
private:
	int model;
	string name;
public:
	void operator=(const train &copy) {
		this->model = copy.model;
		this->name = copy.name;
		cout << "=";
	}
	train(const train &copy) {
		this->model = copy.model;
		this->name = copy.name;
	}
	train(int model, string name) {
		this->model = model;
		this->name = name;
	}
	int get_model() {
		return this->model;
	}
	train() {};
	void out() {
		cout << this->name << " " << this->model<<"\n";
	}
	string get_name() {
		return name;
	}
};
int main()
{
	int number=45,n,model;
	string s;
	int counter;
	ciclestack<int> *stack =new ciclestack<int>();
	ciclestack<Mystruct> *structstack = new ciclestack<Mystruct>();
	ciclestack<train> *trainstack = new ciclestack<train>();
	train mytrain;
	train *train0;
	//MENU
	train *train1;
	train0 = new train();
	train1 = train0;
	while (true) {
		cout << "MENU\n1-ADD ELEMENT\n2-SHOW ELEMENTS\n3-DELETE ELEMENT\n4-SEARCH FOR ELEMENT\n5-SHOW NUMBERED ELEMENT\n6-POP FIRST ELEMENT\n7-SEARCH FOR ELEMENT BY ID\n0-EXIT\n";
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "NAME:";
			cin >> s;
			cout << "MODEL:";
			cin >> model;
			mytrain = train(model,s);
			trainstack->push_first(mytrain);
			break;
		case 2:
			for (int i = 0; i < trainstack->get_length(); i++) {
				trainstack->get_elem(i)->out();
			}
			break;
		case 3:
			cout << "NAME:";
			cin >> s;
			counter = 0;
			for (int i = 0; i < trainstack->get_length(); i++) {
				if (trainstack->get_elem(i)->get_name() == s) {
					trainstack->deleteelem(i);
					counter++;
				}
			}
			if (counter > 0) {
				cout << counter << " RECORDS WERE DELETED\n";
			}
			break;
		case 4:
			cout << "NAME:";
			cin >> s;
			for (int i = 0; i < trainstack->get_length(); i++) {
				if (trainstack->get_elem(i)->get_name() == s) {
					trainstack->get_elem(i)->out();
				}
			}
			break;
		case 5:
			cout << "NUMBER:";
			cin >> number;
			trainstack->get_elem(number)->out();
			break;
		case 6:
			if (trainstack->get_length() > 0) {
				trainstack->get_first()->out();
				trainstack->pop_first();
			}
			break;
		case 7:
			cout << "ID:";
			cin >> number;
			try { 
				if (number < 0) {
					throw IndexOutOfRange();
				} 
				trainstack->get_elem(number)->out(); 
			}
			catch (IndexOutOfRange e) {
				cout << e.what();
			}
			break;
		case 0:
			exit(0);
			break;
		default:
			break;
		}
		system("pause");
		system("CLS");
	}
	
}

