#include "Q5-9.h"

Book::Book(string isbn, int year, string title, Genre genre, string author, string publisher) 
	: isbn(isbn),year(year), title(title), genre(genre), author(author), publisher(publisher), checkedOut(false)
{
	Check_ISBN();
}

void Book::Check_ISBN()
{
	regex isbnFormat("[0-9]{4}-[0-9]{4}-[A-z]");
	while (!regex_match(isbn, isbnFormat))
	{
		cout << "Error: Invalid ISBN. Please enter a valid ISBN in format XXXX-XXXX-X.\n>";
		cin >> isbn;
	}
}

void Book::LoanBook()
{
	if (checkedOut)
	{
		throw exception("Book is already checked out");
	}
	else
	{
		checkedOut = true;
	}
}

void Book::ReturnBook()
{
	if (!checkedOut)
	{
		throw exception("Book is already checked in.");
	}
	else
	{
		checkedOut = false;
	}
}

bool Book::operator==(Book& b)
{
	return isbn == b.isbn;
}

bool Book::operator!=(Book& b)
{
	return isbn != b.isbn;
}

//Output Overload for Book
ostream& operator<<(ostream& o, Book& b)
{

	string bookSummary
	{
		"Book Summary\nISBN: " + b.isbn +
		+"\nYear: " + to_string(b.year)
		+ "\nTitle: " + b.title
		+ "\nAuthor: " + b.author
		+ "\nPublisher: " + b.publisher 
		+ "\n"
	};

	return o << bookSummary;
}


