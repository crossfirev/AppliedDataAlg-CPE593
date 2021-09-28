/*
     Author: Matthew Lepis
	 Date: 9/28/2021
	 Description: CPE593A, HW1b, gcd
	 Citation: Dov Kruger, 2021F Number Theoretic Algorithms, CPE 593
*/
#include <iostream>
using namespace std;

uint64_t gcd(uint64_t a, uint64_t b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main()
{
	uint64_t a, b;

	cout << "Greatest Common Denominator Calulator\n\tFirst Integer\t: ";
	cin >> a;
	cout << "\tSecond Integer\t: ";
	cin >> b;
	cout << "\n\tGCD\t\t: " << gcd(a, b) << endl;
}