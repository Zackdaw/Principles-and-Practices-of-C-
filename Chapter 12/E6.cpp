#include "std_lib_facilities.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

int main(int argc, char** argv)
{

	Fl_Window window{ 5000, 500, "Excercise 6" };

	Fl_Box boxFrame{ 50, 50, 6000, 6000 };
	boxFrame.box(FL_FLAT_BOX);
	boxFrame.color(FL_RED);

	window.show();

	return Fl::run();
}

//A window that is too large is simply put off the screen but may be dragged.
//A shape too big for the window goes off the edge and is allowed to overflow the window and not displayed further.