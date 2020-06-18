#include "std_lib_facilities.h"

int main()
{
	
	string input;

	cout << "Hello! Please enter a number: ";
	cin >> input;

	if (input == "zero")
	{
		cout << "0";
	}
	else if (input == "one") 
	{
		cout << "1";
	}
	else  if (input == "two")
	{
		cout << "2";
	}
	else if (input == "three")
	{
		cout << "3";
	}
	else if (input == "four")
	{
		cout << "4";
	}
	else
	{
		cout << "Uninterpretable input.";
	}

	keep_window_open();
	return 0;
}