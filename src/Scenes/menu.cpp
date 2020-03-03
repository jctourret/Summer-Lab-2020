#include "menu.h"

#include "raylib.h"

using namespace SummerLab;

namespace SummerLab {

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
		DrawText("Fire out!", 500, 500, 20, YELLOW);
		EndDrawing();
	}
}