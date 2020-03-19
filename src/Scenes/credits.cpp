#include "credits.h"

#include "raylib.h"

#include "System/game_states.h"

using namespace SummerLab;

namespace SummerLab {
	credits::credits() {
		_onCreditsTimer = false;
		_background = LoadTexture("res/assets/img/menu/credits.png");
	}

	credits::~credits() {

	}

	void credits::run() {
		update();
		draw();
	}

	void credits::update() {
		runCreditsTimer();
	}

	void credits::draw() {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexture(_background,0,0,RAYWHITE);
		EndDrawing();
	}

	void credits::runCreditsTimer() {
		SetMasterVolume(0.0f);
		_onCreditsTimer += GetFrameTime();
		if (_onCreditsTimer >= 10.f) {
			gameState = onMenu;
			SetMasterVolume(0.02f);
		}
	}
}