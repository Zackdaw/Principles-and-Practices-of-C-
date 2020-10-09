#include "std_lib_facilities.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

int main(int argc, char** argv)
{

	Fl_Window window{ 600, 600, "Excercise 5"};

	Fl_Box boxFrame{ 50, 50, 500, 500 };
	boxFrame.box(FL_FLAT_BOX);
	boxFrame.color(FL_RED);

	Fl_Box boxCenter{ 100, 100, 400, 400 };
	boxCenter.box(FL_FLAT_BOX);
	boxCenter.color(FL_DARK_BLUE);

	window.show();

	return Fl::run();
}