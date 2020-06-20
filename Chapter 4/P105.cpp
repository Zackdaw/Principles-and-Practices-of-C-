#include "std_lib_facilities.h"

int main()
{
	constexpr double YenToDollars = 0.0094;
	constexpr double KronerToDollars = 0.11;
	constexpr double PoundsToDollars = 1.24;

	double currencyAmount;
	char currencyType;

	cout << "Please enter an amount followed by a y, k, or p for the currancy type:\n";
	cin >> currencyAmount >> currencyType;

	if (currencyType == 'y')
	{
		cout << currencyAmount << " yen : " << currencyAmount * YenToDollars << " dollars";
	}
	else if (currencyType == 'k')
	{
		cout << currencyAmount << " kroner : " << currencyAmount * KronerToDollars << " dollars";
	}	
	else if (currencyType == 'p')
	{
		cout << currencyAmount << " pounds : " << currencyAmount * PoundsToDollars << " dollars";
	}	
	else
	{
		cout << "Error: Unknown currency type.";
	}

	keep_window_open();
	return 0;
}