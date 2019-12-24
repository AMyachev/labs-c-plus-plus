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
private:
	int model;
	string name;
public:
	friend ostream& operator<<(ostream& os, const train &foroutput) {
		return os << "Name:" << foroutput.name << "\nModel:" << foroutput.model<<endl;
	}
	train operator=(const train &copy) {
		this->model = copy.model;
		this->name = copy.name;
		return *this;
	}
	train(int model, string name) : model(model), name(name) {}
	train() : model(0), name("") {}
	train(const train &copy) {
		this->model = copy.model;
		this->name = copy.name;
	}
	int get_model() {
		return this->model;
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
	ciclestack<train> *trainstack = new ciclestack<train>();
	train mytrain;
	train *train0;
	train0 = new train();
	//MENU
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
				cout<<*(trainstack->get_elem(i));
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
					cout << *(trainstack->get_elem(i));
				}
			}
			break;
		case 5:
			cout << "NUMBER:";
			cin >> number;
			try {
				if (number < 0) {
					throw IndexOutOfRange();
				}
				cout<<*(trainstack->get_elem(number));
			}
			catch (IndexOutOfRange e) {
				cout << e.what();
			}
			break;
		case 6:
			if (trainstack->get_length() > 0) {
				train0 = trainstack->pop_first();
				cout<<*(train0);
				delete train0;
			}
			break;
		case 7:
			cout << "ID:";
			cin >> number;
			try { 
				if (number < 0) {
					throw IndexOutOfRange();
				} 
				cout << *(trainstack->get_elem(number));
			}
			catch (IndexOutOfRange e) {
				cout << e.what();
			}
			break;
		
		default:
			break;
		}
		system("pause");
		system("CLS");
		if (n == 0) {
			trainstack->~ciclestack();
			delete train0;
			return 0;
		}
		
	}
	
}

