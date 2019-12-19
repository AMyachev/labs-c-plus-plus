// stringclass.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "stringcl.h"
#include "complex.h"
#include <list>
#include <stdlib.h>
using namespace std;

int main()
{
	int n,count=0,counter;
	char *c = new char();
	char *c0 = new char();
	setlocale(LC_ALL, "Russian");
	
	list<stringcl> *strlist= new list<stringcl>();
	list<complex> *cmplxlist = new list<complex>();
	stringcl **strings = new stringcl*[10];
	stringcl *st;
	complex *cmplx;
	complex cmp;
	while (true) {
		cout << "MENU\n1-Add string\n2-Show strings\n5-Add complex\n6-Show complexes\n7-Multiplicate complexes\n8-Search(complex)\n9-Delete\n10-How many times did we call copy constructor\n0-Exit\n";
		n = 11;
		cin >> n;
		switch (n)
		{
		case 0:
			exit(0);
		case 1:
			cin >> c;
			st = &stringcl(c);
			strlist->push_back(*st);
			//strings[count] = st;
			count++;
			break;
		case 2:
			for (list<stringcl>::iterator i = strlist->begin(); i != strlist->end(); i++) {
				i->out();
			}
			//for (int i = 0; i < count; i++) {
			//	strings[i]->out();
			//}
			break;
		case 5:
			cin >> c;
			if (c[1] == '\0') {
				cmplxlist->push_back(complex(c[0]));
			}
			else {
				//cmplx = &complex(c);
				cmplxlist->push_back(complex(c));
			}
			break;
		case 6:
			for (list<complex>::iterator i = cmplxlist->begin(); i != cmplxlist->end(); i++) {
				i->out();
			}
			break;
		case 7:
			cin >> c;
			//cmplxlist->push_back(complex(c));
			cin >> c0;
			cmplxlist->push_back(complex(c0)*complex(c));
			cout << "\n Result:";
			cmplxlist->back().out();
			break;
		case 8:
			cin >> c;
			 counter = 0;
			 cmplx = &complex(c);
			for (list<complex>::iterator i = cmplxlist->begin(); i != cmplxlist->end(); i++) {
				if (*i == complex(c)) {
					counter++;
				}
			}
			if (counter > 0) {
				cout << "FOUND ";
				cout << counter;
				cout << "TIMES\n";
			}
			break;
		case 9:
			cin >> c;
			counter = 0;
			cmplx = &complex(c);
			for (list<complex>::iterator i = cmplxlist->begin(); i != cmplxlist->end(); i++) {
				if (*i == *cmplx) {
					counter++;
				}
			}
			cmplxlist->remove(*cmplx);
			cout << "DELETED " << counter << " OBJECTS\n";
			break;
		case 10:
			cout << cmp.count;
				break;
		default:
			break;
		}
		//system("pause");
		//system("CLS");
		
	}
	
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
