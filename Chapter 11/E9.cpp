#include "std_lib_facilities.h"

const string fileName{ "Binary_Test.bin" };

const string testString{ "Hello world! This is a test line for chapter 11's exercise 09." };

void SaveBinary(string line)
{
	ofstream ofs{ fileName, ios::binary };

	size_t lineSize{ line.size() };
	ofs.write(&reinterpret_cast<char&>(lineSize), sizeof(size_t));
	ofs.write(line.c_str(), lineSize);
	ofs.close();
}

void LoadBinary(string& line)
{
	ifstream ifs{ fileName, ios::binary };

	string temp{ "" };

	size_t lineSize{ 0 };

	ifs.read((char*)&lineSize, sizeof(size_t));
	char* buffer{ new char[lineSize] };
	ifs.read(buffer, lineSize);
	buffer[lineSize] = '\0';
	line = buffer;

	delete[] buffer;

	ifs.close();

}


int main() 
{
	string loadedLine{ "" };

	SaveBinary(testString);
	cout << testString << "\n\n";
	LoadBinary(loadedLine);
	cout << loadedLine;

}