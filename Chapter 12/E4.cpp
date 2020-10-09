#include "std_lib_facilities.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

int main(int argc, char** argv)
{

	const int x{ 3 }, y{ 3 };

	Fl_Window* window{ new Fl_Window(600, 600) };

	window->begin();

	for (int i{ 0 }; i < x; i++)
	{
		for (int j{ 0 }; j < y; j++)
		{
			Fl_Box* Box{ new Fl_Box(50 + (50*i), (50) + (50*j), 45, 45) };
			Box->box(FL_BORDER_BOX);
			if (((j + 1) + (i * x)) % 2) 
			{
				Box->color(FL_RED);
			}
			else
			{
				Box->color(FL_WHITE);
			}

		}
	}

	window->end();
	window->show(argc, argv);

	return Fl::run();
}