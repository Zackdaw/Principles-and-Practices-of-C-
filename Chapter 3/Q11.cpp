#include "std_lib_facilities.h"

int main()
{
	int pennies, nickels, dimes, quarters, halves;
	double dollars;
	string pLabel, nLabel, dLabel, qLabel, hLabel;

	cout << "Please enter your number of Pennies, Nickles, Dimes, Quarters, and Half Dollars:\n";

	cin >> pennies >> nickels >> dimes >> quarters >> halves;

	dollars = (pennies + nickels * 5 + dimes * 10 + quarters * 25 + halves * 50) / 100.00;

	if (pennies != 1)
	{
		pLabel = "pennies";
	}
	else
	{
		pLabel = "penny";
	}
	if (nickels != 1)
	{
		nLabel = "nickels";
	}
	else
	{
		nLabel = "nickel";
	}
	if (dimes != 1)
	{
		dLabel = "dimes";
	}	
	else
	{	
		dLabel = "dime";
	}
	if (quarters != 1)
	{
		qLabel = "quarters";
	}	
	else
	{	
		qLabel = "quarter";
	}
	
	if (halves != 1)
	{
		hLabel = "half-dollars";
	}	
	else
	{	
		hLabel = "half-dollar";
	}


	cout << "You have:\n"
		<< pennies << " " << pLabel << '\n'
		<< nickels << " " << nLabel << '\n'
		<< dimes << " " << dLabel << '\n'
		<< quarters << " " << qLabel << '\n'
		<< halves << " " << hLabel << '\n'
		<< "You have $" << dollars << '\n';

	keep_window_open();
	return 0;
}