#include "Q5-9.h"

int main()
{

	//Date Test
	//Date date{ 1970, 1, 1 };

	//for (int i = 0; i < 375; i++)
	//{
	//	date.AddDays(10);
	//	cout << date << '\n';
	//}

	vector<Book> testCatalogue
	{
		{ "1234-5678-A", 1937, "The Hobbit", Genre::Fantasy, "JRR Tolkien", "Allen & Unwin" },		
		{ "1234-5678-B", 1925, "The Great Gatsby", Genre::Fiction, "F. Scott Fitzgerald", "Charles Scribner's Sons" },
		{ "1234-5678-C", 2019, "Modern Cybernetics", Genre::NonFiction, "Eldon Tyrell", "Tyrell " },
		{ "1234-5678-D", 1965, "Dune", Genre::ScienceFiction, "Frank Herbert", "Penguin Random House" },
		{ "1234-5678-E", 1816, "Mansfield Park", Genre::Fiction, "Jane Austen", "John Murray" },
		{ "1234-5678-F", 1353, "The Decameron", Genre::Fiction, "Giovanni Boccaccio", "Filippo and Bernardo Giunti" },

	};

	vector<Patron> testPatrons
	{
		{ 12345, "Roy Batty" },
		{ 23456, "Chell"},
		{ 86753, "Jenny"},
		{ 93517, "Geralt"},
	};

	Library testLibrary{ testCatalogue, testPatrons };

	testLibrary.LoanItem("The Hobbit", "Roy Batty", LongDate{ 2019, 5, 1 });

	cout << testLibrary.transactions[0];

	testLibrary.LoanItem("Modern Cybernetics", "Roy Batty", LongDate{ 2016, 5, 1 });

	cout << testLibrary.patrons[0];

	testLibrary.ReturnItem("The Hobbit", "Roy Batty");

	cout << testLibrary.patrons[0];
}