#include "Q5-9.h"

Library::Library(vector<Book> b, vector<Patron> p) : books{ b }, patrons{ p }, transactions{}
{
}

void Library::LoanItem(string bookName, string patronName, LongDate d)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].title == bookName)
		{
			for (int j = 0; j < patrons.size(); j++)
			{
				if (patrons[j].name == patronName)
				{
					patrons[j].LoanBook(books[i]);
					transactions.push_back(Transaction{ books[i], patrons[j], d });
				}
			}
		}
	}
}

void Library::ReturnItem(string bookName, string patronName)
{
	for (int i = 0; i < transactions.size(); i++)
	{
		if (transactions[i].book.title == bookName && transactions[i].patron.name == patronName)
		{
			transactions[i].patron.ReturnBook(transactions[i].book.title);
		}
	}

}


