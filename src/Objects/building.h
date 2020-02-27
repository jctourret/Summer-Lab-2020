#ifndef BUILDING_H
#define BUILDING_H

#include "raylib.h"
#include "Objects/window.h"

namespace SummerLab {

	const int numberOfWindows = 9;

	class building {
	private:
		Rectangle _body;
		int _floors;
		int _columns;
		window* _windows[numberOfWindows];
		Color _color;
	public:
		building(float height, float width, float x, float y, int floors, int columns);
		~building();
		void initFire();
		void growFireTimers();
		void dozeFireTimers(Rectangle rec);
		void spreadFireTimers();
		void draw();
	};
}
#endif