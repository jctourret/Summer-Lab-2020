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
		float _growTimer;
		float _dozeTimer;
		float _spreadTimer;
		Texture2D _smallFire1;
		Texture2D _smallFire2;
		Texture2D _smallFire3;

		Texture2D _mediumFire1;
		Texture2D _mediumFire2;
		Texture2D _mediumFire3;

		Texture2D _largeFire1;
		Texture2D _largeFire2;
		Texture2D _largeFire3;
	public:
		window(float height, float width, float x, float y);
		~window();
		float getWindowWidth();
		float getWindowHeight();
		float getWindowX();
		float getWindowY();
		bool getOnFire();
		void catchFire();
		void dozeFire();
		void growFire();
		void growFireTimer();
		void dozeFireTimer();
		void spreadFireTimer();
		void draw();
	};
}
#endif