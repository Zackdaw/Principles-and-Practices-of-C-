#include "std_lib_facilities.h"

int main()
{
	vector<string>blacklist = { "world", "hello" };
	vector<string>sentence;

	cout << "Please enter a sentence:\n";
	for (string temp; cin >> temp;)
	{
		sentence.push_back(temp);
		cout << "Number of words: " << sentence.size() << '\n';
	}

	for (string s : sentence)
	{
		string output = s;
		for (string b : blacklist)
		{
			if (s == b)
			{
				output = "BEEP";
			}
		}
		cout << output << ' ';
	}

	keep_window_open();
	return 0;

}