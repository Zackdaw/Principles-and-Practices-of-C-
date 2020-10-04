#include "std_lib_facilities.h"

int main()
{
	int valD{}, valO{}, valH{};

	cin >> valD >> oct >> valO >> hex >> valH;

	cout << showbase << "Hex: " << hex << setw(6) << valH << "\tConverts to: " << dec << setw(6) << valH << '\n';
	cout << "Oct: " << oct << setw(6) << valO << "\tConverts to: " << dec << setw(6) << valO << '\n';
	cout << "Dec: " << dec << setw(6) << valD << "\tConverts to: " << setw(6) << valD << '\n';

	return 0;
}