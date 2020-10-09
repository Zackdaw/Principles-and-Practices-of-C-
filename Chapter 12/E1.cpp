#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"

int main()
{

	Simple_window win{ Point{100, 100}, 600, 600, "Exercise 1" };

	Graph_lib::Rectangle rect{ Graph_lib::Point{150, 150}, 100, 100 };
	rect.set_color(Color::blue);

	Graph_lib::Polygon poly{};
	poly.add(Point{400, 400});
	poly.add(Point{500, 400});
	poly.add(Point{500, 500});
	poly.add(Point{400, 500});

	poly.set_color(Color::red);

	win.attach(rect);
	win.attach(poly);

	win.wait_for_button();
	
	return 0;

}