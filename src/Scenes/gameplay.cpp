#include "gameplay.h"

#include "raylib.h"

#include "System/screen.h"

using namespace SummerLab;

namespace SummerLab {

	static const float buildingHeight = 600;
	static const float buildingWidth = 600;
	static const int buildingFloors = 3;
	static const int buildingColumns = 3;
	static const float truckHeight= 100;
	static const float truckWidth = 250;
	static const Color truckColor = RED;

	gameplay::gameplay() {
		_gameplayOn = false;
		_toMenu = false;
		_toCredits = false;
		_truck = new truck(truckHeight,truckWidth, screenWidth/2, screenHeight-(screenHeight/5));
		_building = new building(buildingHeight,buildingWidth, screenWidth/2 -(buildingWidth/2), screenHeight/10, buildingFloors, buildingColumns );
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
		_truck->move();
	}

	void gameplay::draw() {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Gameplay", 500, 500, 20, RED);
		_building->draw();
		_truck->draw();
		EndDrawing();
	}

}