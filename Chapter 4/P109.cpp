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


	switch (currencyType)
	{
	case 'y':
		cout << currencyAmount << " yen : " << currencyAmount * YenToDollars << " dollars";
		break;
	case 'k':
		cout << currencyAmount << " kroner : " << currencyAmount * KronerToDollars << " dollars";
		break;
	case 'p':
		cout << currencyAmount << " pounds : " << currencyAmount * PoundsToDollars << " dollars";
		break;
	default:
		cout << "Error: Unknown currency type.";
		break;
	}

	keep_window_open();
	return 0;
}