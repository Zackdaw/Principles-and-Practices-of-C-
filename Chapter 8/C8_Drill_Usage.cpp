#include "C8_H.h";
#include <iostream>

int foo = 7;

int main()
{
	print_foo();
	print(99);

	int x = 10;
	int y = 5;

	std::cout << "X: " << x << ", " << "Y: " << y << '\n';

	swap_r(x, y);

	std::cout << "X: " << x << ", " << "Y: " << y << '\n';

	X::var = 69;
	X::print();

	using namespace Y;
	var = 68;
	print();
	X::print();
	using Z::var;
	using Z::print;
	var = 32;
	print();
	Y::print();
	X::print();

	std::cout << "\n-------COMPLETE-------\n";

	return 0;


}