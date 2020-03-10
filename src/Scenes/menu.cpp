#include "menu.h"

#include "raylib.h"
#include "System/screen.h"

using namespace SummerLab;

namespace SummerLab {
	static const int titlePosX = screenWidth / 2;
	static const int titlePosY = screenHeight/6;
	static const int titleFontSize = 50;
	static const int textFontSize = 20;
	static const int playPosX = screenWidth / 2;
	static const int playPosY = screenHeight - screenHeight/6;


	static const Color textColor = MAROON;

	menu::menu(){
		_menuOn = true;
		_toGameplay = false;
		_toCredits = false;
	}

	menu::~menu(){

	}

	void menu::setToGameplay(bool toGameplay){
		_toGameplay = toGameplay;
	}

	void menu::setToCredits(bool toCredits) {
		_toCredits = toCredits;
	}

	bool menu::getToGameplay() {
		return _toGameplay;
	}

	bool menu::getToCredits(){
		return _toCredits;
	}

	void menu::run() {
		_menuOn = true;
		while (_menuOn && !WindowShouldClose()) {
			update();
			draw();
		}
	}

	void menu::update() {
		if (IsKeyPressed(KEY_ENTER)) {
			_menuOn = false;
			_toGameplay = true;
		}
	}

	void menu::draw() {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("FIRE OUT!", titlePosX-(TextLength("FIRE OUT!")/2), titlePosY, titleFontSize, textColor);
		DrawText("Press ENTER to SAVE THE DAY!", playPosX - (TextLength("Press ENTER to SAVE THE DAY!")/2), playPosY, textFontSize, textColor);
		EndDrawing();
	}
}