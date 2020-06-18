#include "std_lib_facilities.h"

int main()
{
	double num = 0;
	while (cin>>num)
	{
		int i = num;
		char c = i;
		int i2 = c;
		cout << "num == " << num << '\n'
			<< "i ==" << i << '\n'
			<< "c ==" << c << '\n'
			<< "i2 ==" << i2 << '\n';
	}

	keep_window_open();
	return 0;
}