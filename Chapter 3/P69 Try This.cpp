#include "std_lib_facilities.h"

int main()
{
	cout << "Please enter an integer: ";
	int num;
	cin >> num;
	cout << "num == " << num << "\n"
		<< "num + 1 == " << num + 1 << "\n"
		<< "num * 3 == " << num * 3 << "\n"
		<< "num + num == " << num + num << "\n"
		<< "num^2 == " << num * num << "\n"
		<< "num/2 == " << (num / 2) + (num % 2) << "\n"
		<< "sqrt(num) ==" << sqrt(num) << "\n"
		<< "\n";
}