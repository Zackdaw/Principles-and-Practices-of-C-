#include "C8_H.h"
#include <iostream>

namespace X
{
	int var;

	void print()
	{
		std::cout << "X: " << var << '\n';
	}
}

namespace Y
{
	int var;

	void print()
	{
		std::cout << "Y: " << var << '\n';
	}
}
namespace Z
{
	int var;

	void print()
	{
		std::cout << "Z: " << var << '\n';
	}
}