#include "std_lib_facilities.h";
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	Simple_window win{ Point{150, 150}, 600, 600, "Exercise 2" };

	Graph_lib::Rectangle rect{ Point(150, 150), 100, 30 };
	Graph_lib::Text t{ Point{180, 170}, "Howdy!" };

	rect.set_color(Color::black);
	rect.set_fill_color(Color::red);

	win.attach(rect);
	win.attach(t);

	win.wait_for_button();

	return 0;

}