#include "std_lib_facilities.h"
#include <queue>

// 0 = verb, 1 = noun, 2 = article, 3 = conjunction, 9 = terminator.

class Token
{
public:
	string word;
	int value;

	Token(string word, int value)
		:word(word), value(value) {};
private:
};

char terminator = '.';

vector<string> verbs = { "fly", "swim" };
vector<string> nouns = { "birds", "fish" };
vector<string> articles = { "the" };
vector<string> conjunctions = { "and" };

bool IsVerb(string word);
bool IsNoun(string word);
bool IsArticle(string word);
bool IsConjunction(string word);
bool sentence(Token entry);


queue<Token> words;

int main()
{
	string buffer;
	while (cin)
	{
		cin >> buffer;
		if (IsVerb(buffer))
		{
			words.push(Token(buffer, 0));
		}		
		else if (IsNoun(buffer))
		{
			words.push(Token(buffer, 1));
		}		
		else if (IsArticle(buffer))
		{
			words.push(Token(buffer, 2));
		}		
		else if (IsConjunction(buffer))
		{
			words.push(Token(buffer, 3));
		}
		else if (buffer == ".")
		{

			words.push(Token(buffer, 9));
			break;
		}
	}

	Token t = words.front();
	words.pop();

	if (sentence(t))
	{
		cout << "\nSENTENCE OK\n";
	}

	return 0;
}

bool sentence(Token entry)
{
	Token t = words.front();
	words.pop();
	cout << "Sentence Cycle: " << entry.word << "\n";
	switch (entry.value)
	{
	case 0:
	{
		if (t.value == 3)
		{
			return sentence(t);
		}
		else if (t.value == 9)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	case 1:
	{
		if (t.value == 0)
		{
			return sentence(t);
		}
		else
		{
			return false;
		}
	}
	case 2:
	{
		if (t.value == 1)
		{
			return sentence(t);
		}
		else
		{
			return false;
		}
	}
	{
	case 3: 
	{
		if (t.value == 1 || t.value == 2)
		{
			return sentence(t);
		}
		else
		{
			return false;
		}
	}
	}
	default:
		return false;
	}
}


bool IsVerb(string word)
{
	if (find(verbs.begin(), verbs.end(), word) != verbs.end())
	{
		return true;
	}
	return false;
}
bool IsNoun(string word)
{
	if (find(nouns.begin(), nouns.end(), word) != nouns.end())
	{
		return true;
	}
	return false;
}
bool IsArticle(string word)
{
	if (find(articles.begin(), articles.end(), word) != articles.end())
	{
		return true;
	}
	return false;
}
bool IsConjunction(string word)
{
	if (find(conjunctions.begin(), conjunctions.end(), word) != conjunctions.end())
	{
		return true;
	}
	return false;
}
