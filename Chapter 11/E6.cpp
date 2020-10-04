#include "std_lib_facilities.h"

string sampleLine{ "Hello, this is a sample text. It is the best!" };

void puct_to_whitespace(string& line)
{
	char ch;
	istringstream iss{ line };
	line = "";
	while (iss >> noskipws >>ch)
	{
		if (ispunct(ch) && !(ch == '\"' || ch == '\''))
		{
			if (iss.peek() == ' ')
			{
				line += "";
			}
			else
			{
				line += " ";
			}
		}
		else
		{
			line += ch;
		}
	}

}

int main()
{
	cout << sampleLine << '\n';
	puct_to_whitespace(sampleLine);
	cout << sampleLine;
}