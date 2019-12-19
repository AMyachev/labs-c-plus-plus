#include "pch.h"
#include "complex.h"
#include <iostream>
#include <cmath>
#include <string>


complex::complex()
{
}
void complex::operator=(const complex &cplx) {
	*this= complex(cplx);
}
complex::complex(const complex &cmplx) {
	count++;
	this->length = cmplx.length;
	this->re = cmplx.re;
	this->im = cmplx.im;
	this->c = (char *)calloc(sizeof(char), length);
	for (int i = 0; i < length; i++) {
		this->c[i] = cmplx.c[i];
	}
}
complex::complex(const char *c) {
	//говно
	re = im = 0;
	bool notacomplex = false;
	int i=0;
	char *restr=(char *)malloc(sizeof(char));
	char *imstr = (char *)malloc(sizeof(char));
	if (c[0] == '+') {
		reznak = true;
		i++;
	}
	else {
		if (c[0] == '-') {
			reznak = false;
			i++;
		}
	}
	int redigit = 0,imdidit=0;
	for (i; c[i] != 'i' && c[i]!='\0'; i++) {
		if (c[i]<'0' || c[i]>'9') {
			notacomplex = true;
			break;
		}
		this->re = this->re * 10 + c[i] - '0';
		redigit++;
		restr = (char *)realloc(restr,sizeof(char)*redigit);
		restr[redigit-1] = c[i];
		
	}
	if (c[i] == 'i') i++;
	if (c[i] == '-') {
		imznak = false;
		i++;
	}
	else {
		if (c[i] == '+') {
			imznak = true;
			i++;
		}
	}
	
	for (i; c[i] != '\0'; i++) {
		if (c[i]<'0' || c[i]>'9') {
			notacomplex = true;
			break;
		}
		else {
			this->im = this->im * 10 + c[i] - '0'; 
			imdidit++;
			imstr = (char *)realloc(imstr, sizeof(char)*imdidit);
			imstr[imdidit-1] = c[i];
			
		}
	}
	
	length = i;
	this->c = (char *)calloc(sizeof(char), length);
	i = 0;
	
	
	i = 0;
	int j;
	if (notacomplex) {
		length = 1;
		re = im = 0;
		reznak = imznak = true;
		this->c[0] = '0';
	}
	else {
		if (re > 0) {
			if (!reznak) this->c[i] = '-';
			for (j = 0; j < redigit; j++) {
				this->c[i] = restr[j];
				i++;
			}
		}
		if (im > 0) {
			this->c[i] = 'i';
			i++;
			if (!imznak) { this->c[i] = '-'; i++; }
			for (j = 0; j < imdidit; j++) {
				this->c[i] = imstr[j];
				i++;
			}
		}
	}
}
complex complex::operator*(const complex &cplx1) {
	
	bool icheck = false;
	int rec = 1 , imc = 1;
	this->re = this->re*cplx1.re;
	this->im = (this->im*cplx1.im);
	this->imznak = !this->imznak;
	int j = 0,i;
	for (i = re; i != 0; j++) { i = i / 10; rec=rec*10; }
	this->length = 0;
	length += j;
	j = 0;
	for (i = im; i != 0; j++) { i = i / 10; imc=imc*10; }
	length += j;
	length++;
	int re0 = this->re,im0=this->im;
	rec = rec / 10;
	imc = imc / 10;
	if (!reznak) {
		length++;
		c[0] = '-';
	}
	if (!imznak) { length++; }
	for (i = 1; i < length; i++) {
		if (i==length-j-1 && !imznak) {
			
			this->c[i] = '-';
		}
		else {
			if (rec==0 && !icheck) {
				this->c[i] = 'i';
				icheck = true;
			}
			else {
				if (!icheck) {
					this->c[i] = (re0 / rec)%10 + '0';
					rec = rec / 10;
				}
				else {
					this->c[i] = (im0 / imc)%10 + '0';
					imc=imc / 10;
				}
			}
		}
		
	}
	return *this;
}
bool complex::operator==(const complex &cmplx) {
	if (reznak == cmplx.reznak && imznak == cmplx.imznak && re == cmplx.re && im == cmplx.im) {
		return true;
	}
	else return false;
}
complex::complex(char c) {
	this->c = (char *)calloc(sizeof(char),1);
	if (c > '9' || c < '0') {
		
			length = 1;
			re = im = 0;
			reznak = imznak = true;
			this->c[0] = '0';
		
	}
	else { re = c - '0'; this->c[0] = c; }
		length = 1;

	reznak = imznak = true;
}
int complex::copycount() {
	return count;
}
complex::~complex()
{
	//std::cout << "DESTROYED\n";
}
