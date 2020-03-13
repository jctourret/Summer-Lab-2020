#ifndef MENU_H
#define MENU_H

#include "raylib.h"
#include "Objects/truck.h"

namespace SummerLab {
	
	class menu {
	private:
		bool _menuOn;
		bool _toGameplay;
		bool _toCredits;
		float _toGameplayTimer;
		float _toCreditsTimer;
		Rectangle _playButton;
		Rectangle _creditsButton;
		truck* _menuTruck;
		Texture2D _background;
		Texture2D _logo;
		Texture2D _menuButtons;
		Texture2D _playShine;
		Texture2D _creditsShine;
	public:
		menu();
		~menu();
		void setToGameplay(bool toGameplay);
		void setToCredits(bool toCreditos);
		bool getToGameplay();
		bool getToCredits();
		void run();
		void update();
		void draw();
		void playMenuTheme();
		void shootButtons(Rectangle rec);
		bool isPlayButtonShot(Rectangle rec);
		bool isCreditsButtonShot(Rectangle rec);
	};
}
#endif
