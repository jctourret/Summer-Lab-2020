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
		Color _color;
		Rectangle _fireBody;
		bool _onFire;
		fire _fire;
	public:
		window(float height, float width, float x, float y);
		~window();
		float getWindowWidth();
		float getWindowHeight();
		float getWindowX();
		float getWindowY();
		void catchFire();
		void dozeFire();
		void growFire();
		void growFireTimer();
		void dozeFireTimer();
		void draw();
	};
}
#endif