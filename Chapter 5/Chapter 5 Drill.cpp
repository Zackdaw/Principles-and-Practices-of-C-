#include "std_lib_facilities.h"
#include "Chapter 5 Drill.h"

int main()
{
	try
	{
		D01(); Blank();
		D02(); Blank();
		D03(); Blank();
		D04(); Blank();
		D05(); Blank();
		D06(); Blank();
		D07(); Blank();
		D08(); Blank();
		D09(); Blank();
		D10(); Blank();
		D11(); Blank();
		D12(); Blank();
		D13(); Blank();
		D14(); Blank();
		D15(); Blank();
		D16(); Blank();
		D17(); Blank();
		D18(); Blank();
		D19(); Blank();
		D20(); Blank();
		D21(); Blank();
		D22(); Blank();
		D23(); Blank();
		D24(); Blank();
		D25(); Blank();

		keep_window_open();
		return 0;
	}
	catch (exception& e)
	{
		cerr << "Error: " << e.what() << '\n';
		keep_window_open();
		return 1;
	}
	catch (...) 
	{
		cerr << "Unknown Exception Thrown\n";
		keep_window_open();
		return 2;
	}
}

/*---------------Answer Functions-------------------*/

void D25()
{
	cout << "25. Success!\n";
}

void D24()
{
	int x = 4; 
	double d = 5 / (x - 2);
	if (d = (x - 2.0) + 0.5)
	{
		cout << "24. Success!\n";
	}
}

void D23()
{
	int i = 0;
	int j = 9;
	while (i < 10)
		i++;
	if (j < i)
		cout << "23. Success!\n";
}

void D22()
{
	string s = "22. Success!\n";
	for (int i = 0; i < s.length(); i++)
	{
		cout << s[i];
	}
}

void D21()
{
	int x = 2; 
	double d = 5.0 / x;

	if (d == x + 0.5)
	{
		cout << "21. Success!\n";
	}

}

void D20()
{
	int i = 0;
	int j = 9;
	while (i < 10)
		i++;
	if (j < i)
	{
		cout << "20. Success!\n";
	}
}

void D19()
{
	vector<int> v(5);
	for (int i = 0; i < v.size(); i++);
	cout << "19. Success!\n";
}

void D18()
{
	string s = "18. Success!\n";
	for (int i = 0; i < s.length(); i++)
	{
		cout << s[i];
	}
}

void D17()
{
	int x = 20; // Changed from 2000 to 20 to avoid narrowing info loss.
	char c = narrow_cast<char>(x);
	if (c == x)
	{
		cout << "17. Success!\n";
	}
	else
	{
		cout << "17. Failure!\n";
	}
}

void D16()
{
	if (true) 
	{
		cout << "16. Success!\n";
	}
	else
	{
		cout << "16. Failure!\n";
	}
}

void D15()
{
	string s = "15. Success!\n";
	for (int i = 0; i < 6; i++);
	cout << s;
}

void D14()
{
	vector<char> v = { 'a', 'b', 'c', 'd', 'e' };
	for (int i = 0; i < v.size(); ++i)
	{
		v[i];
	}
	cout << "14. Success!\n";
}

void D13()
{
	vector<char> v(5); 
	for (int i = 0; i < v.size(); i++)
	{
		i;
	}
	cout << "13. Success!\n";
}

void D12()
{
	string s = "ape";
	if (s > "Fool")
	{
		cout << "12. Success!\n";
	}
	else
	{
		cout << "12. Failed!\n";
	}
}

void D11()
{
	string s = "ape";
	if (s.compare("Fool") != 0)
	{
		cout << "11. Success!\n";
	}
	else
	{
		cout << "11. Failed!\n";
	}
}

void D10()
{
	string s = "ape";
	if (s.compare("Fool") != 0)
	{
		cout << "10. Success!\n";
	}
	else
	{
		cout << "10. Failed!\n";
	}

}

void D09()
{
	string s = "ape";
	bool c = "Fool" < s;
	if (c)
	{
		cout << "09. Success!\n";
	}
	else
	{
		cout << "09. Failed!\n";
	}
}

void D08()
{
	bool c = false;
	if (!c)
	{
		cout << "08. Success!\n";
	}
	else
	{
		cout << "08. Failed\n";
	}

}

void D07()
{
	//7
	if (true)
	{
		cout << "07. Success!\n";
	}
	else
	{
		cout << "07. Failed!\n";
	}
}

void D06()
{
	//6
	vector<int> v(10);
	v[5] = 7;
	if (v[5] == 7)
	{
		cout << "06. Success!\n";
	}
}

void D05()
{
	int res = 7;
	vector<int> v(10);
	v[5] = res;
	cout << "05. Success!\n";
}

void D04()
{
	//4
	cout << "04. Success!" << '\n';
}

void D03()
{
	//3
	cout << "03. Success" << "!\n";
}

void D02()
{
	//2
	cout << "02. Success!\n";
}

void D01()
{
	//1
	cout << "01. Success!\n";
}

void Blank()
{
	cout << '\n';
}