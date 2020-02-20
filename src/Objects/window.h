#ifndef WINDOW_H
#define WINDOW_H

#include "raylib.h"

namespace SummerLab {
	
	enum fire {
		noFire,
		smallFire,
		mediumFire,
		largeFire,
	};

	class window {
	private:
		Rectangle _body;
		bool _onFire;
		fire _fire;
		Color _color;
	public:
		window(float height, float width, float x, float y);
		~window();
		void catchFire();
		void dozeFire();
		void growFire();
		void draw();
	};
}
#endif