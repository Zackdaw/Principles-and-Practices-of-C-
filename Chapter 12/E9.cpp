#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

int main()
{
	const string Title{ "Cat.jpg" };

	Simple_window win{ Point{50, 50}, 737, 739, Title };

	Image img{ Point{50, 50}, Title };

	Text txt{ Point{350, 725}, Title };
	txt.set_color(Color::black);
	txt.set_font_size(32);

	win.attach(img);
	win.attach(txt);

	win.wait_for_button();

	return 0;
}