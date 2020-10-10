#define _USE_MATH_DEFINES

#include "Graph.h"
#include "Simple_window.h"
#include <cmath>

int main(int argc, char** argv)
{
	Simple_window win{ Point{25, 25}, 800, 800, "Exerise 11" };

	Graph_lib::Closed_polyline triangle{ };
	triangle.add(Point{ 360, 420 });
	triangle.add(Point{ 440, 420 });
	triangle.add(Point{ 400, 420- static_cast<int>(tan((60 * (M_PI / 180))) * 40) });
	triangle.set_color(Color::black);

	Graph_lib::Closed_polyline quad;
	quad.set_color(Color::black);

	quad.add(Point(360, 420 -(tan((60 * (M_PI / 180))) * 40)));
	quad.add(Point(440, 420 -(tan((60 * (M_PI / 180))) * 40)));
	quad.add(Point(440, 500 -(tan((60 * (M_PI / 180))) * 40)));
	quad.add(Point(360, 500 -(tan((60 * (M_PI / 180))) * 40)));

	Graph_lib::Closed_polyline pentagon;
	pentagon.set_color(Color::black);

	Point center(400, (460 -(tan((60 * (M_PI / 180))) * 40)));
	Graph_lib::Circle cl(center, 2);
	cl.set_color(Color::black);

	double radius = 64;

	double s1 = sin((2 * M_PI) / 5) * radius;
	double c1 = cos(M_PI / 5) * radius;

	double s2 = sin((2 * M_PI) / 5) * radius;
	double c2 = cos((4 * M_PI) / 5) * radius;

	vector<double> pentaX;
	vector<double> pentaY;

	for (int i = 0; i < 5; i++) {
		pentaX.push_back(radius * cos(2 * M_PI * i / 5));
		pentaY.push_back(radius * sin(2 * M_PI * i / 5));
	}
	for (int i = 0; i < 5; i++) {
		pentagon.add(Point(pentaX[i] + center.x + 6, pentaY[i] + center.y));
	}

	win.attach(cl);
	win.attach(triangle);
	win.attach(quad);
	win.attach(pentagon);
	win.wait_for_button();


	return 0;
}
