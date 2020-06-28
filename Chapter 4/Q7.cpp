#include "std_lib_facilities.h"

int main()
{
	int HandleInput(string input);

	string input1, input2;

	int num1 = 0, num2 = 0, product = 0;

	char operand = '+';

	cout << "Please enter a number, an operand, and a number: ";

	cin >> input1 >> operand >> input2;
	num1 = HandleInput(input1);
	num2 = HandleInput(input2);

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

	cout << num1 << ' ' << operand << ' ' << num2 << " = " << product;

	return 0;
}


int HandleInput(string input)
{
	vector<string> numbers = { "zero", "one", "two", "three", "four", "five","six", "seven", "eight", "nine" };

	transform(input.begin(), input.end(), input.begin(), tolower);

	for (int i = 0; i < numbers.size(); i++)
	{
		if (input == numbers[i] || (static_cast<int>(input[0]) - 48) == i)
		{
			return i;
		}
	}
	
}