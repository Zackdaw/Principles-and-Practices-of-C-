#include "std_lib_facilities.h"

int main()
{
	double a = 1, b = 4, c = -5;
	double x1, x2;

	double root;

	cout << "Please enter three numbers: \n";
	cin >> a >> b >> c;

	root = sqrt((b * b) - (4 * a * c));
	x1 = (-b + root) / (2 * a);
	x2 = (-b - root) / (2 * a);

	cout << "Quadratic solution: \n";
	cout << x1 << '\n' << x2;

	return 0;

}