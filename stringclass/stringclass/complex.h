#pragma once
#include "stringcl.h"
#include <string>
class complex : public stringcl
{
public:
	complex();
	complex(char c);
	complex(const char *c);
	complex(const complex &cmplx);
	complex operator*(const complex &cplx1);
	bool operator==(const complex &cplx1);
	void operator=(const complex &cplx1);
	int copycount();
	~complex();
private:
	int re;
	int im;
	bool reznak = true;
	bool imznak = true;
};

