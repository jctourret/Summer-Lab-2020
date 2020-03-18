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
		bool _keyboardGame;
		bool _hoseGame;
		float _toGameplayTimer;
		float _toCreditsTimer;
		float _toKeyboardTimer;
		float _toHoseTimer;
		Rectangle _playButton;
		Rectangle _creditsButton;
		Rectangle _hoseButtonRec;
		Rectangle _keyboardButtonRec;
		truck* _menuTruck;
		Texture2D _background;
		Texture2D _logo;
		Texture2D _menuButtons;
		Texture2D _playShine;
		Texture2D _creditsShine;
		Texture2D _keyboardButton;
		Texture2D _keyboardButtonShine;
		Texture2D _hoseButton;
		Texture2D _hoseButtonShine;
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
		bool getKeyboardGame();
		bool getHoseGame();
		void shootButtons(Rectangle rec);
		bool isPlayButtonShot(Rectangle rec);
		bool isCreditsButtonShot(Rectangle rec);
		bool isKeyboardButtonShot(Rectangle rec);
		bool isHoseButtonShot(Rectangle rec);
	};
}
#endif
