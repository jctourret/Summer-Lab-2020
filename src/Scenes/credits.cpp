#include "credits.h"

#include "raylib.h"



using namespace SummerLab;

namespace SummerLab {
	credits::credits() {
		_creditsOn = false;
		_toGameplay = false;
		_toMenu = false;
	}

	credits::~credits() {

	}

	void credits::setToMenu(bool toMenu) {
		_toMenu = toMenu;
	}

	void credits::setToGameplay(bool toGameplay) {
		_toGameplay = toGameplay;
	}

	bool credits::getToGameplay() {
		return _toGameplay;
	}

	bool credits::getToMenu() {
		return _toMenu;
	}

	void credits::run() {
		_creditsOn = true;
		while (_creditsOn) {
			update();
			draw();
		}
	}

	void credits::update() {
		if (IsKeyPressed(KEY_ENTER)) {
			_creditsOn = false;
			_toMenu = true;
		}
	}

	void credits::draw() {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("credits", 200, 500, 50, MAROON);
		EndDrawing();
	}
}