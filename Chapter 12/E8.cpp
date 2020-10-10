#include "Graph.h"
#include "Simple_window.h"

int main(int argc, char** argv)
{
	try 
	{
		Simple_window window{ Point{50, 50}, 700, 700, "Exercise 08" };

		Circle ring_0{ Point{100, 100}, 50};
		ring_0.set_color(Color::blue);
		window.attach(ring_0);		
		
		Circle ring_1{ Point{155, 160}, 50 };
		ring_1.set_color(Color::yellow);
		window.attach(ring_1);

		Circle ring_2{ Point{210, 100}, 50};
		ring_2.set_color(Color::black);
		window.attach(ring_2);

		Circle ring_3{ Point{265, 160}, 50 };
		ring_3.set_color(Color::green);
		window.attach(ring_3);

		Circle ring_4{ Point{320, 100}, 50};
		ring_4.set_color(Color::red);
		window.attach(ring_4);

		window.wait_for_button();

		return 0;
	}
	catch (...)
	{

	}
}