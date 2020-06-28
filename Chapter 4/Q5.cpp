#include "std_lib_facilities.h"

int main()
{
	double num1 = 0, num2 = 0, product = 0;

	char operand = '+';

	cout << "Please enter a number, an operand, and a number: ";

	cin >> num1 >> operand >> num2;

	switch (operand)
	{
	case '+':
		product = num1 + num2;
		break;
	case '-':
		product = num1 - num2;
		break;
	case '*':
		product = num1 * num2;
		break;
	case '/':
		product = num1 / num2;
		break;
	default:
		cout << "Invalid input.";
		break;
	}

	cout << num1 << ' ' <<  operand << ' ' << num2 << " = " << product;

	return 0;
}
