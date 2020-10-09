#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"

int main()
{
	Point tl{ 100, 100 };

	Axis xa{ Axis::x, Point{50, 550}, 500, 10, "X-Axis" };
	xa.set_color(Color::black);
	xa.label.set_color(Color::blue);

	Axis ya{ Axis::y, Point{50, 550}, 500, 10, "Y-Axis" };
	ya.set_color(Color::black);
	ya.label.set_color(Color::blue);

	Function sine{ sin, 0, 50, Point{50, 250}, 1000, 10, 10 };
	sine.set_color(Color::dark_red);

	Graph_lib::Polygon poly;
	poly.add(Point{ 5, 5 });
	poly.add(Point{ 5, 595 });
	poly.add(Point{ 595, 595 });
	poly.add(Point{ 595, 5 });

	Graph_lib::Rectangle rect{ Point{350, 350}, 50, 50 };
	rect.set_fill_color(Color::red);

	poly.set_color(Color::dark_blue);
	poly.set_style(Line_style::dash);

	Text t{ Point{240, 240}, "Hello World!" };

	Simple_window win{ tl, 600, 600, "Canvas 01" };
	
	win.attach(xa);
	win.attach(ya);
	win.attach(sine);
	win.attach(poly);
	win.attach(rect);
	win.attach(t);

	win.wait_for_button();

	return 0;
}