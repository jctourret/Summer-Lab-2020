#include "gameplay.h"

#include "raylib.h"

using namespace SummerLab;

namespace SummerLab {

	gameplay::gameplay() {
		_gameplayOn = false;
		_toMenu = false;
		_toCredits = false;
	}

	gameplay::~gameplay() {

	}
	void gameplay::setToMenu(bool toMenu) {
		_toMenu = toMenu;
	}

	void gameplay::setToCredits(bool toCredits) {
		_toCredits = toCredits;
	}

	bool gameplay::getToCredits() {
		return _toCredits;
	}

	bool gameplay::getToMenu() {
		return _toMenu;
	}

	void gameplay::run() {
		_gameplayOn = true;
		while (_gameplayOn) {
			update();
			draw();
		}
	}

	void gameplay::update() {
		if (IsKeyPressed(KEY_ENTER)) {
			_gameplayOn = false;
			_toCredits = true;
		}
	}

	void gameplay::draw() {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Gameplay", 500, 500, 20, RED);
		EndDrawing();
	}

}