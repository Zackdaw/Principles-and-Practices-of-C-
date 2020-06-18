#include "std_lib_facilities.h"

int main()
{
	string op;
	int num1;
	int num2;

	cout << "Please enter an operator as well as two numbers:\n";

	cin >> op >> num1 >> num2;

	if (op == "+" || op == "add")
	{
		cout << num1 + num2;
	}	
	
	else if (op == "-" || op == "sub")
	{
		cout << num1 - num2;
	}
	else if (op == "*" || op == "mul")
	{
		cout << num1 * num2;
	}
	else if (op == "/" || op == "div")
	{
		cout << num1 / num2;
	}
	else
	{
		cout << "Inadequate input.";
	}

	keep_window_open();
	return 0;
}