#include "std_lib_facilities.h"

int main()
{
	double num1, num2, num3;

	cout << "Please enter three numbers: ";
	cin >> num1 >> num2 >> num3;
	double buffer;

	if (num3 > num2)
	{
		buffer = num2;
		num2 = num3;
		num3 = buffer;
	}	
	if (num2 > num1)
	{
		buffer = num1;
		num1 = num2;
		num2 = buffer;
	}

	cout << "Ordered List: "
		<< num1 << ', ' << num2 << ', ' << num3 << '\n';

	return 0;
}
