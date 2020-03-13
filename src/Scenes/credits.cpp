#include "credits.h"

#include "raylib.h"



using namespace SummerLab;

namespace SummerLab {
	credits::credits() {
		_creditsOn = false;
		_toGameplay = false;
		_toMenu = false;
		_onCreditsTimer = false;
		_background = LoadTexture("res/assets/img/menu/credits.png");
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
		runCreditsTimer();
	}

	void credits::draw() {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexture(_background,0,0,RAYWHITE);
		EndDrawing();
	}

	void credits::runCreditsTimer() {
		_onCreditsTimer += GetFrameTime();
		if (_onCreditsTimer >= 10.f) {
			_creditsOn = false;
			_toMenu = true;
		}
	}
}