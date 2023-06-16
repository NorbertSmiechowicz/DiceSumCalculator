#pragma once
#include<iostream>
#include<cstdlib>
#include<cmath>

class complex {
public:
	float re, im;
	complex(float = 0, float = 0);
	void print();
};

class cpolynomial {
public:
	int n;
	complex z, a[10];
	complex value();
	float UnitRes(int m, int t);
	void print();
	cpolynomial(int = 10);
};

complex cprod(complex z1, complex z2);
complex cadd(complex z1, complex z2);
complex cdiv(complex z1, complex z2);
complex cpower(complex z, int n);

