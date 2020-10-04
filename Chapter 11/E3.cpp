#include "std_lib_facilities.h"

Vector<string> Read_File_To_Vector(string& fileName)
{
	Vector<string> fileContents{};
	string line{ "" };

	ifstream inFile{ fileName };
	if (inFile.is_open())
	{
		int i{ 0 };
		cout << "Reading File Line: (";
		while (getline(inFile, line))
		{
			cout << i << " ";
			fileContents.push_back(line);
			i++;
		}
		cout << ")\nFile Reading Complete.\n\n";
	}
	else
	{
		throw exception("Exception: File cannot be read and is either invalid, corrupt, or inaccessible.\n");
	}

	inFile.close();

	return fileContents;
}

void Disemvowel(Vector<std::string>& fileContents)
{

	string vowels{ "aeiouAEIOU" };


	for (int i{ 0 }; i < fileContents.size(); i++)
	{
		char ch{};
		string modifiedString{ "" };
		istringstream iss{fileContents[i]};

		while (iss >> std::noskipws >> ch)
		{
			if (vowels.find(ch) != std::string::npos)
			{
				modifiedString += '_';
			}
			else
			{
				modifiedString += ch;
			}
		}
		fileContents[i] = modifiedString;
	}

	return;
}

int main()
{
	string fileName{ "" }, word{ "" };
	Vector<string> fileContents{};

	while (true)
	{
		cout << "Please enter a file name to open: \n>";
		getline(cin, fileName);
		try
		{
			fileContents = Read_File_To_Vector(fileName);
			break;
		}
		catch (exception& e)
		{
			cout << e.what() << '\n';
			continue;
		}
	}

	Disemvowel(fileContents);

	for (string& line : fileContents)
	{
		cout << line << "\n\n";
	}


	return 0;
}