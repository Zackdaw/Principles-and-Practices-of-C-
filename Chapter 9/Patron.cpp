#include "Q5-9.h";

Patron::Patron(int userID, string name) : userID{ userID }, name{ name }, balance{ 0 }, loanedItems{}
{}

void Patron::LoanBook(Book& book)
{
	book.LoanBook();
	loanedItems.push_back(book);
}

void Patron::ReturnBook(string bookName)
{
	for (int i = 0; i < loanedItems.size(); i++)
	{
		if (bookName == loanedItems[i].title)
		{
			loanedItems[i].ReturnBook();
			loanedItems.erase(loanedItems.begin() + i);
			return;
		}
	}
	throw exception("Book not found in user's list.");
}

bool Patron::HasBalance()
{
	return balance > 0;
}

ostream& operator<<(ostream& o, Patron& b)
{
	cout << "\nUserID: " + to_string(b.userID)
		+ "\nName: " + b.name
		+ "\nCurrent Balance: " + to_string(b.balance)
		+ "\nBooks On Loan:\n";

	for (auto book : b.loanedItems)
	{
		cout << '\n' << book;
	}

	return o;
}