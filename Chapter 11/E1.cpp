#include "std_lib_facilities.h"

string Read_File_To_String(string filepath)
{
	ifstream inFile{ filepath, std::ios_base::out };
	string rString{ "" };
	char ch;

	while (inFile >> ch)
	{
		rString += tolower(ch);
	}

	inFile.close();
	return rString;
}

int main()
{
	string rString = Read_File_To_String("E1_Test.txt");

	cout << rString;
}