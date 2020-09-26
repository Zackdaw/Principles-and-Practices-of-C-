#include "E5_Header.h"

const string fileName{ "E5_Test.txt" };

int main()
{
	ofstream outFile{ fileName, std::ofstream::trunc };

	Month m{ "Febtober", 31 };

	outFile << m;

	outFile.close();

	ifstream inFile{ fileName };

	Month r{};

	inFile >> r;

	cout << r;

	inFile.close();
}