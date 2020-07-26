#include "C7_Header.h"

Token TokenStream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch (ch)
	{
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '^':
	case '=':
	{
		return Token(ch);
	}
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{
		cin.unget();
		double val;
		cin >> val;
		return Token(number, val);
	}
	case let:
		return Token(let);
	default:
		if (isalpha(ch))
		{
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
			cin.unget();
			cout << s;
			if (s == "sqrt") return Token(squareRoot);
			if (s == "k") return Token(number, 1000);
			if (s == "exit") return Token(quit);
			return Token(name, s);
		}
		error("Bad token");
	}
}

void TokenStream::putback(Token t) 
{ 
	buffer = t; 
	full = true; 
}

void TokenStream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}