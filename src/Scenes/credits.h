#ifndef CREDITS_H
#define CREDITS_H

#include "raylib.h"

namespace SummerLab {
	class credits {
	private:
		bool _creditsOn;
		bool _toMenu;
		bool _toGameplay;
		float _onCreditsTimer;
		Texture2D _background;
	public:
		credits();
		~credits();
		void setToMenu(bool toMenu);
		void setToGameplay(bool toGameplay);
		bool getToMenu();
		bool getToGameplay();
		void run();
		void update();
		void draw();
		void runCreditsTimer();
	};

}
#endif