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

	return fileContents;
}

bool Find_Word(string& word, string& target)
{
	return target.find(word) != std::string::npos;
}

void Word_Search(std::string& word, Vector<std::string>& fileContents)
{
	bool found{ false };
	for (int i{ 0 }; i < fileContents.size(); i++)
	{
		if (Find_Word(word, fileContents[i]))
		{
			cout << i + 1 << ": " << fileContents[i] << '\n';
			found = true;
		}
	}
	if (!found)
	{
		cout << "Word not found in file.";
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

	cout << "Please enter a word to search:\n>";
	cin >> word;
	cout << "Searching Document for: " << word << "\n\n";


	Word_Search(word, fileContents);

	return 0;
}