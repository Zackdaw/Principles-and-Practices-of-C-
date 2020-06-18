#include "std_lib_facilities.h"

int main()
{
	int num;

	cout << "Please enter a number: ";
	cin >> num;

	if (num % 2 == 0)
	{
		cout << num << " is an even number.";
	}
	else
	{
		cout << num << " is an odd number.";
	}

}