#pragma once
#include <string>

class stringcl
{
public:
	static int count;
	stringcl(char *c);
	stringcl(char c);
	stringcl(const stringcl &s);
	void clear();
	int Length();
	void out();
	stringcl();
	~stringcl();
protected:
	char *c;
	int length=0;

};

