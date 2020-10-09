#include "std_lib_facilities.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>

int main(int argc, char** argv)
{

	Fl_Window window{ 1600, 800, "Excercise 7" };

	Fl_Box grass{ 0, 750, 1600, 50 };
	grass.box(FL_FLAT_BOX);
	grass.color(FL_DARK_GREEN);

	Fl_Box* house{ new Fl_Box{400, 250, 800, 500} };
	house->box(FL_FLAT_BOX);
	house->color(FL_DARK_RED);

	Fl_Box* door{ new Fl_Box{750, 500, 100, 250} };
	door->box(FL_FLAT_BOX);
	door->color(FL_DARK_YELLOW);

	window.show();

	return Fl::run();
}