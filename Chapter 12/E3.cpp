#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	Simple_window win{ Point{150, 150}, 600, 600, "Exercise 2" };

	Graph_lib::Open_polyline z;
	z.add(Point{ 25, 50 });
	z.add(Point{ 125, 50 });
	z.add(Point{ 25, 200 });
	z.add(Point{ 125, 200 });

	z.set_style(Line_style(Line_style::solid, 5));
	z.set_color(Color::black);

	Graph_lib::Open_polyline j;
	j.add(Point{ 175, 50 });
	j.add(Point{ 275, 50 });
	j.add(Point{ 225, 50 });
	j.add(Point{ 225, 200 });
	j.add(Point{ 175, 200 });
	j.add(Point{ 175, 175 });

	j.set_style(Line_style(Line_style::solid, 5));
	j.set_color(Color::blue);

	win.attach(z);
	win.attach(j);

	win.wait_for_button();

	return 0;

}