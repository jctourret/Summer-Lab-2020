#include "screen.h"

using namespace SummerLab;

namespace SummerLab {

	screen::screen() {
		_resolution.width = screenWidth;
		_resolution.height = screenHeight;
	}

	screen::~screen() {

	}
	void screen::setScreenWidth(int width) {
		_resolution.width = width;
	}
	void screen::setScreenHeight(int height) {
		_resolution.height = height;
	}
	int screen::getScreenWidth() {
		return _resolution.width;
	}
	int screen::getScreenHeight() {
		return _resolution.height;
	}
}


screen::screen()
{
}


screen::~screen()
{
}
