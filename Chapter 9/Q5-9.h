#pragma once
#include "std_lib_facilities.h"

enum class Genre
{
	Fiction, NonFiction, ScienceFiction, Fantasy, Mystery, Thriller
};

class Book
{
public:
	Book(string isbn, int year, string title, Genre genre, string author, string publisher);

	string isbn;
	int year;
	string title;
	Genre genre;
	string author;
	string publisher;

	void LoanBook();

	void ReturnBook();

	friend ostream& operator<<(ostream& o, Book& b);
	bool operator==(Book& b);
	bool operator!=(Book& b);

private:

	bool checkedOut;

	void Check_ISBN();
};

class LongDate
{
public:
	LongDate();
	LongDate(short year, short month, short day);

	friend ostream& operator<<(ostream& o, LongDate date);
	friend bool operator<(LongDate a, LongDate b);
	friend bool operator>(LongDate a, LongDate b);
	friend bool operator==(LongDate a, LongDate b);
	friend bool operator!=(LongDate a, LongDate b);
	friend LongDate operator+(LongDate a, int b);

	void AddDays(int days);

private:
	short year;
	short month;
	short dayNum;
	bool leap;

	void Determine_Leap_Year();
	void Validate_Date();

};

class Patron
{
public:
	Patron(int userID, string name);

	string name;

	void LoanBook(Book& book);

	void ReturnBook(string bookName);

	bool HasBalance();

	friend ostream& operator<<(ostream& o, Patron& b);

private:

	int userID;

	float balance;
	vector<Book> loanedItems;

};

struct Transaction
{
	Transaction(Book& b, Patron& p, LongDate& d) : book{ b }, patron{ p }, checkDate{ d }, dueDate{}
	{
		dueDate = checkDate + 7;
	};
	Book& book;
	Patron& patron;
	LongDate& checkDate;
	LongDate dueDate;

	friend ostream& operator<<(ostream& o, Transaction t) 
	{
		return o << t.book << t.patron << "CheckDate:" << t.checkDate<< "Due Date:" << t.dueDate;
	};
};


class Library
{
public:
	Library(vector<Book> b, vector<Patron> p);

	void LoanItem(string bookName, string patronName, LongDate d);
	void ReturnItem(string bookName, string patronName);

	vector<Book> books;
	vector<Patron> patrons;
	vector<Transaction> transactions;

private:

};
