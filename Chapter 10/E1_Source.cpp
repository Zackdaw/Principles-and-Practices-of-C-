#include "E1_Header.h"

int main() 
{
	const string fname{ "E1_Number_List.txt" };

	Vector<int> numbers{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	fstream fileOut{ fname, std::fstream::out |std::fstream::in| std::fstream::trunc };

	for (auto n : numbers)
	{
		fileOut << n << ' ';
	}

	fileOut.seekg(0);

	int i{ 0 };
	for (int p; fileOut >> p;)
	{
		cout << p << " ";
		i += p;
	}
	fileOut.close();

	cout << "\n\nSummation: " << i << "\n";

	return 0;

}