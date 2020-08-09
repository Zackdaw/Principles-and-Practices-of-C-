#include "C8_H.h"
#include "std_lib_facilities.h"

void print_foo()
{
	cout << "Foo: " << foo << '\n';
}

void print(int input)
{
	cout << "Printing Input: " << input << '\n';
}

void swap_r(int& x, int& y)
{
	int z = x;
	x = y;
	y = z;

}
