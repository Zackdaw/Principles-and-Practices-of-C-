
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.

	Drill Instructions for Portability

	01. Starting from the file below, get the calculator to compile. // Done
	02. Go through the entire program and add appropriate comments. // Done
	03. As you commented, fix any errors that you found. // Done
	04. Prepare a set of inputs and use them to test the calculator. Is your list
		pretty complete? What should you look for? Include negative values, 0, very small,
		very large, and absurd inputs. // Done
	05. Fix any bugs uncovered by testing. // Done
	06. Add a predefined name k meaning 1000. // Done
	07. Give the user a usable square root function.
	08. Catch attempts to take the square root of a negative numer and print an appropriate
		error message.// Done
	09. Allow the user to use the ^ operator to conduct exponential operations.// Done
	10. Change the delcaration keyword from let to #. // Complete;
	11. Change the quit keyword from quit to exit. // Complete;
*/

#include "std_lib_facilities.h"

void clean_up_mess();

//Token class exists to classify input as either operators, variables, or numbers.
class Token {
public:
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string n) : kind(ch), value(0), name(n)  {}
};

//The token stream allows for tokens to be taken out and replaced, allowing for greater flexibility and look-ahead
//functionality.
class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void putback(Token t) { buffer = t; full = true; }

	void ignore(char);
};

const char let = '#';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char squareRoot = 'I';

// The get function returns the appropriate token from the token stream.
Token Token_stream::get()
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
				while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_') ) s += ch;
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

// Required so the token stream can ignore abnormal input.
void Token_stream::ignore(char c)
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

struct Variable 
{
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

double GetSquareRoot(double d)
{
	if (d < 0)
	{
		error("Square Roots of negative numbers are undefined.");
	}
	else
	{
		return sqrt(d);
	}
}

Token_stream ts;
double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
		//For parenthesis in particular, reloop to expression if an opening parenthesis is detected. Then return the total of that subloop upon detecting a closing parenthesis.
	case '(':
	{	
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("'(' expected");
		return d;
	}
	case '-':
		return -primary();
	case squareRoot:
		cout << "Case statement Reached\n";
		return GetSquareRoot(primary());
	case number:
		return t.value;
	case name:
	{
		return get_value(t.name);
	}
	default:
		error("primary expected");
		clean_up_mess();
	}
}

double secondary()
{
	double left = primary();
	while (true)
	{
		Token t = ts.get();
		switch (t.kind)
		{
		case '^':
			left = pow(left, primary());
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double term()
{
	double left = secondary();
	while (true) 
	{
		Token t = ts.get();
		switch (t.kind) 
		{
		case '*':
			left *= secondary();
			break;
		case '/':
			{	
				double d = secondary();
				if (d == 0) error("divide by zero");
				left /= d;
				break;
			}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double declaration()
{
	// Get the token following the let statement.
	Token t = ts.get();
	// Throw an error if the type doesn't match that of a valid name, such as a number instead.
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	//Check if the name is already declared, since we cannot reassign variables.	
	if (is_declared(name)) error(name, " declared twice");
	//Get the next token, check and make sure it uses the assignment operator '=', and then run expression() if so.
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	//Add the new variable with the name and value to the variable vector.
	names.push_back(Variable(name, d));
	return d;
}

double statement()
{
	//Get the token from the stream. This would be the token put back into the stream by the Calculate() function for the first call.
	Token t = ts.get();
	switch (t.kind) {
		//If the token is a Let, return the declaration function's results.
	case let:
		return declaration();
		//Otherwise, put the token back into the stream and return the results of the expression() function.
	default:
		ts.putback(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try {
		//Display the prompt.
		cout << prompt;
		// Get the latest token.
		Token t = ts.get();
		// If the token is a print token, get the next token.
		while (t.kind == print) t = ts.get();
		// If the token is a quit token, quit.
		if (t.kind == quit) return;
		// Put the token back into the stream.
		ts.putback(t);
		//Print the result constant char, run the statement() function, then insert the end line character and flushes the buffer using endl.
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

//Main in this context simply to execute the calculate function and catch any exceptions that come up from it.
int main()
{
	try {
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >> c && c != ';');
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin >> c && c != ';');
		return 2;
	}
}