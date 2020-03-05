
#ifndef SCREEN_H
#define SCREEN_H

#include "raylib.h"

namespace SummerLab {

	const int screenWidth = 1920;
	const int screenHeight = 1080;

	struct Resolution {
		int width;
		int height;
	};

	class screen {
	private:
		Resolution _resolution;
	public:
		screen();
		~screen();
		void setScreenWidth(int width);
		void setScreenHeight(int height);
		int getScreenWidth();
		int getScreenHeight();
	};
}
#endif