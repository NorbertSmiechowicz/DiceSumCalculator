#include <iostream>
#include<cstdlib>
#include"zespolone.h"
#include<cmath>
using namespace std;

int main()
{
	cpolynomial poly(6);
	for (int i = 0; i < 6; i++) {
		poly.a[i].re = 1;
		poly.a[i].im = 0;
	}

	int k = 0, l = 0;
	cout << "Intput a desired sum: ";
	cin >> k;
	cout << "Input a number of throws: ";
	cin >> l;

	int n;
	float o = poly.UnitRes(k + 1, l);
	
	n = (int)o;
	if (o - (float)n > 0) n++;

	cout << "The number of possible combinations for a total value of " << k << " in " << l << " throws is:\n" << n << endl;
	cout << "The probability of such a value is: \n" << (float)n / (float)pow(6,l) * 100 << "%";

	return 0;
}

