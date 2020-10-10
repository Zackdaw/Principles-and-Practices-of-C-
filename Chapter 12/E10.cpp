// While I appreciate this exercise, I do not think that creating the entire graph is a worthwhile use of time since it 
// simply repeated functions over and over due to the constraints imposed by using Graph.h and Simple_window.
// The code below shows the primary usages of the functions for creating windows, layered windows, text, and lines.

#include "Graph.h"
#include "Simple_window.h"

int main()
{
	Simple_window window{ Point{25, 25}, 1200, 1200, "Exercise 10" };

#pragma region Point.h

	Graph_lib::Rectangle pointRect{ Point{50, 50}, 150, 40 };
	
	pointRect.set_color(Color::black);
	pointRect.set_fill_color(Color::yellow);

	Text pointHeadText{ Point{50, 45}, "Point.h" };
	pointHeadText.set_color(Color::black);
	pointHeadText.set_font_size(16);
	pointHeadText.set_font(Font::helvetica_bold);

	Text pointBodyText{ Point{65, 75}, "struct Point{...};" };
	pointBodyText.set_color(Color::black);
	pointBodyText.set_font_size(16);
	pointBodyText.set_font(Font::helvetica_bold);

	window.attach(pointRect);
	window.attach(pointHeadText);
	window.attach(pointBodyText);

#pragma endregion
#pragma region FLTKHeaders

	Graph_lib::Rectangle bgRect_0{ Point{438, 13}, 150, 40 };
	bgRect_0.set_color(Color::black);
	bgRect_0.set_fill_color(Color::yellow);

	Graph_lib::Rectangle bgRect_1{ Point{444, 19}, 150, 40 };
	bgRect_1.set_color(Color::black);
	bgRect_1.set_fill_color(Color::yellow);

	Graph_lib::Rectangle fltkHeadersRect{ Point{450, 25}, 150, 40 };
	fltkHeadersRect.set_color(Color::black);
	fltkHeadersRect.set_fill_color(Color::yellow);

	Text fltkHeadersText(Point{ 472, 50 }, "FLTK Headers");
	fltkHeadersText.set_color(Color::black);
	fltkHeadersText.set_font_size(16);
	fltkHeadersText.set_font(Font::helvetica);

	window.attach(bgRect_0);
	window.attach(bgRect_1);
	window.attach(fltkHeadersRect);
	window.attach(fltkHeadersText);

#pragma endregion
#pragma region FLKTCode

	Graph_lib::Rectangle bgRect_2{ Point{738, 38}, 100, 40 };
	bgRect_2.set_color(Color::black);
	bgRect_2.set_fill_color(Color::yellow);

	Graph_lib::Rectangle bgRect_3{ Point{744, 44}, 100, 40 };
	bgRect_3.set_color(Color::black);
	bgRect_3.set_fill_color(Color::yellow);

	Graph_lib::Rectangle fltkCodeRect{ Point{750, 50}, 100, 40 };
	fltkCodeRect.set_color(Color::black);
	fltkCodeRect.set_fill_color(Color::yellow);

	Text fltkCodeText(Point{ 760, 75 }, "FLTK Code");
	fltkCodeText.set_color(Color::black);
	fltkCodeText.set_font_size(16);
	fltkCodeText.set_font(Font::helvetica);

	window.attach(bgRect_2);
	window.attach(bgRect_3);
	window.attach(fltkCodeRect);
	window.attach(fltkCodeText);

#pragma endregion
#pragma region Lines

	Line codeToHeaders{ Point{738, 58}, Point{600, 45} };
	codeToHeaders.set_color(Color::black);

	window.attach(codeToHeaders);

#pragma endregion



	window.wait_for_button();

	return 0;
}