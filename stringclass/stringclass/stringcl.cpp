#include "pch.h"
#include "stringcl.h"
#include <iostream>
#include <string>

using namespace std;

stringcl::stringcl()
{
}
stringcl::stringcl(char *c) {
	for (length = 0; c[length] != '\0'; length++) {
	}
	this->c = (char *)calloc(sizeof(char), length);
	
	for (int i = 0; i < length; i++) {
		this->c[i] = c[i];
	}
}
int stringcl::count = 0;
void stringcl::out() {
	for (int i = 0; i < length; i++) {
		cout << c[i];
	}
	cout << "\n";
}
stringcl::stringcl(char c) {
	this->c = (char *)malloc(sizeof(char));
	this->c[0] = c;
	length = 1;
}
stringcl::stringcl(const stringcl &s) {
	//static int count = 0;
	count++;
	this->c = (char *)calloc(sizeof(char), s.length);
	for (int i = 0; i < s.length; i++) {
		this->c[i] = s.c[i];
	}
	this->length = s.length;
}
void stringcl::clear() {
	length = 0;
	c = '\0';
}

int stringcl::Length() {
	return this->length;
}
stringcl::~stringcl()
{
	//cout << "STRING DELETED";
	//out();
}
