#include <iostream>
#include "ComplexReader.h"
#include "Complex.h"
#include "Menu.h"
#include <algorithm>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;

Menu mainMenu, subMenu;
File file;
ComplexReader complexFile;


void generateComplex(Complex* destination, int n) {
	for (int i = 0; i < n; i++) {
		destination[i] = { (double)(rand() % 20), (double)(rand() % 20) };
	}
}

void pickFile(File* fileHandler) {
	string filename;
	
	cout << "������� ���� � �����:\n>";
	cin >> filename;

	fileHandler->open(filename);

	subMenu.run();
}

void readFromFile(File* fileHandler, bool isShowDialog=false) {
	int symbAmount = fileHandler->length();

	if (isShowDialog) {
		cout << "������� ���-�� �������� ��� ����������:\n>";
		cin >> symbAmount;
	}
	else {
		fileHandler->seek(0);
	}

	
	string fileContent = fileHandler->read(symbAmount);
	cout << fileContent;

	system("pause");
}


void setPosition(File* fileHandler) {
	int newPosition = 0;

	cout << "������������� �������: " << fileHandler->getPosition() << " | ������ �����: " << fileHandler->length() << "\n"
		 << "������� ����� �������:\n>";

	cin >> newPosition;
	
	fileHandler->seek(newPosition);
}

void readToFile(File* fileHandler, bool isAppending) {
	string content = "", curString="";

	while (getline(cin, curString)) {
		content += curString + "\n";
	}

	if (isAppending) {
		fileHandler->append(content);
	}
	else {
		fileHandler->write(content);
	}
	
}

void clearFile(File* fileHandler) {
	fileHandler->clear();
}

void readComplex(ComplexReader* fileHandler) {

	vector<Complex> data(fileHandler->size());
	fileHandler->getAsArray(data.data());

	cout << "vector<Complex> data : \n";
	for (Complex complex : data) {
		cout << "\t" << complex << "\n";
	}

	system("pause");
}

void writeComplex(ComplexReader* fileHandler) {
	int complexAmount = 0;

	cout << "������� ����������� ����� ��������?\n>";
	cin >> complexAmount;

	vector<Complex> data(complexAmount);
	generateComplex(data.data(), complexAmount);

	cout << "��������������� ������������������:\n";

	for (Complex complex : data) {
		cout << "\t" << complex << "\n";
	}

	fileHandler->appendArray(data.data(), data.size());
	cout << "done.\n";

	system("pause");
}

void getComplexFileSize(ComplexReader* fileHandler) {
	cout << "���-�� ����������� ����� � �����: " << fileHandler->size() << "\n";
	system("pause");
}


vector<menuItem> subOptionsFile = {
	{"������� ���� ����", []() {readFromFile(&file); } },
	{"������� N ��������", []() {readFromFile(&file, true); }},
	{"�������� ������", []() {readToFile(&file, false); }},
	{"�������� ������ � �����", []() {readToFile(&file, true); }},
	{"�������� ����", []() {clearFile(&file); }},
	{"���������� �������", []() {setPosition(&file); }}
};

vector<menuItem> subOptionsComplexFile = {
	{"������� ������� � ������", []() {readComplex(&complexFile); } },
	{"�������� N ��������", []() {writeComplex(&complexFile); }},
	{"�������� ����", []() {clearFile(&complexFile); }},
	{"���-�� ��������", []() {getComplexFileSize(&complexFile); }}
};

vector<menuItem> mainOptions = {
	{"������� ����", []() {
			subMenu.set_menu(subOptionsFile, "�������� ��������");
			pickFile(&file);
		}},
	{"������� ���� ������������ �����", []() {
			subMenu.set_menu(subOptionsComplexFile, "�������� ��������");
			pickFile(&complexFile);
		}}
};


void init() {
	setlocale(LC_ALL, "rus");

	mainMenu.set_menu(mainOptions, "�������� ��������:");
}

int main() {
	init();

	mainMenu.run();

}