#include "Q2H.h"
#include <iostream>
using namespace std;

vector<int> Fibonacci(const int& x, const int& y, const int& length)
{
	vector<int> fibonacci{ x, y };
	for (int i = 0; i < length; i++)
	{
		if (INT32_MAX - fibonacci[i] < fibonacci[i + 1])
		{
			cout << "WARNING\nOverflow detected beyond (" << fibonacci.back() <<"). Remaining sequence aborted.\n\n";
			break;
		}
		else
		{
			fibonacci.push_back(fibonacci[i] + fibonacci[i + 1]);
		}
	}
	return fibonacci;
}

int main()
{
	int x{ 1 };
	int y{ 2 };
	int length{ 50 };

	vector<int> sequence = Fibonacci(x, y, length);


	string label = "Fibonacci Sequence";
	print(label, sequence);
}