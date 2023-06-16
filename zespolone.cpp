#include"zespolone.h"
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

#define PI 3.14159265

complex::complex(float t1, float t2) {
	re = t1;
	im = t2;
}

void complex::print() {
	cout << "(" << re << " + " << im << "i)";
}

complex cprod(complex z1, complex z2) {
	complex z0(z1.re * z2.re - z1.im * z2.im, z1.re * z2.im + z1.im * z2.re);
	return z0;
}

complex cadd(complex z1, complex z2) {
	complex z0(z1.re + z2.re, z1.im + z2.im);
	return z0;
}

complex cdiv(complex z1, complex z2) {
	z2.im = -z2.im;
	complex z0 = cprod(z1, z2);
	z0.re = z0.re / (z2.re * z2.re + z2.im * z2.im);
	z0.im = z0.im / (z2.re * z2.re + z2.im * z2.im);
	return z0;
}

complex cpower(complex z, int o) {
	complex ztemp;
	ztemp.re = z.re;
	ztemp.im = z.im;
	complex k(1.0, 0.0);
	if (o == 0) { return k; }

	
	if (o > 0) {
		for (int i = 0; i < o-1; i++)
		{
			z = cprod(z, ztemp);
		}
		return z;
	}
	if (o < 0) {
		o = -o;
		z.re = 1;
		z.im = 0;
		for (int i = 0; i < o; i++)
		{
			z = cdiv(z, ztemp);
		}
		return z;
	}
	
}

cpolynomial::cpolynomial(int b) {
	n = b;
}

complex cpolynomial::value() {
	complex v;
	for (int i = 0; i < 10; i++) {
		if (a[i].re != NULL) {
			v = cadd(v, cprod(a[i], cpower(z, n - i)));
		}
	}
	return v;
}

float cpolynomial::UnitRes(int m, int t) {
	complex sum, dz, f, ztemp(1, 0);
	z.re = 1;
	z.im = 0;
	for (int i = 0; i <= 400; i++)
	{
		z.re = cos(PI * (float)i / 200);
		z.im = sin(PI * (float)i / 200);
		dz.re = z.re - ztemp.re;
		dz.im = z.im - ztemp.im;
		ztemp.re = z.re;
		ztemp.im = z.im;
		f = cdiv(cpower(value(), t), cpower(z, m));
		sum = cadd(sum, cprod(f, dz));
	}
	complex p(0, 2 * PI);
	return cdiv(sum, p).re;
}

void cpolynomial::print() {
	for (int i = 0; i < 10; i++) {
		if (a[i].re != 0 || a[i].im != 0) {
			cout << " + ";
			a[i].print();
			cout << " z* ^" << n - i;
		}
	}
}

