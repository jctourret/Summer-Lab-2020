#include "gameplay.h"

#include "raylib.h"

#include "System/screen.h"

using namespace SummerLab;

namespace SummerLab {

	static const float buildingHeight = 600;
	static const float buildingWidth = 600;
	static const int buildingFloors = 3;
	static const int buildingColumns = 3;

	static const int maxDeadCivs = 3;

	static const float truckHeight= 100;
	static const float truckWidth = 250;
	static const Color truckColor = RED;

	gameplay::gameplay() {
		_gameplayOn = false;
		_toMenu = false;
		_toCredits = false;
		_truck = new truck(truckHeight,truckWidth, screenWidth/2, screenHeight-(screenHeight/5));
		_building = new building(buildingHeight,buildingWidth, screenWidth/2 -(buildingWidth/2), screenHeight/10, buildingFloors, buildingColumns );
		_hydrant = new Hydrant(screenWidth / 5, screenHeight - (screenHeight / 4));
		_deadCivs = 0;
		Image background = LoadImage("../res/assets/img/FondoNivel1.jpg");
		ImageResize(&background,1280,720);
		_background = LoadTextureFromImage(background);
		UnloadImage(background);
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
		while (_gameplayOn && !WindowShouldClose()) {
			update();
			draw();
		}
	}

	void gameplay::update() {
		if (IsKeyPressed(KEY_ENTER)) {
			_gameplayOn = false;
			_toCredits = true;
		}
		_building->initFire();
		_building->growFireTimers();
		_building->dozeFireTimers(_truck->getWaterShot());
		_building->spreadFireTimers();
		_building->spawnCiv();
		_building->civJumpTimers();
		_truck->move();
		_truck->recharge(_hydrant->getBody());
		_truck->shoot();
		checkCiviliansBounce();
		bounceCivilians();
		checkCivilianDeath();
		gameResult();
	}

	void gameplay::draw() {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexture(_background, 0,0,RAYWHITE);
		DrawRectangle(10, 10, 50, 50, RAYWHITE);
		_building->draw();
		_truck->draw();
		_hydrant->draw();
		EndDrawing();
	}

	void gameplay::checkCiviliansBounce() {
		for (int i = 0; i < (buildingColumns*buildingFloors); i++){
			if (_truck->checkLeftBounce(_building->getCivilianBody(i))) {
				_building->setCivBounceDirection(i, Left);
				_building->resetCivBounce(i);
			}
			if (_truck->checkUpBounce(_building->getCivilianBody(i))) {
				_building->setCivBounceDirection(i, Up);
				_building->resetCivBounce(i);
			}
			if (_truck->checkRightBounce(_building->getCivilianBody(i))) {
				_building->setCivBounceDirection(i, Right);
				_building->resetCivBounce(i);
			}
		}
	}

	void gameplay::bounceCivilians() {
		for (int i = 0; i < (buildingColumns*buildingFloors); i++){
			_building->civBounce(i);
		}
	}

	void gameplay::checkCivilianDeath() {
		for (int i = 0; i < buildingColumns * buildingFloors; i++){
			if (_building->getCivIsAlive(i)){
				_building->killCivilians(i);
				if (!_building->getCivIsAlive(i)){
					_deadCivs++;
				}
			}
		}
	}

	void gameplay::gameResult() {
		if (_deadCivs >= maxDeadCivs) {
			_gameplayOn = false;
			_toMenu = true;
			_deadCivs = 0;
		}
	}

}