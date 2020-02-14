#pragma once
#ifndef SCREEN_H
#define SCREEN_H

namespace SummerLab {

	const int screenWidth = 1280;
	const int screenHeight = 720;

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

class screen
{
public:
	screen();
	~screen();
};
