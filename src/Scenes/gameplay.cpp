#include "gameplay.h"

#include "raylib.h"

#include "System/screen.h"

using namespace SummerLab;

namespace SummerLab {

	static const float buildingHeight = 700;
	static const float buildingWidth = 500;
	static const int buildingFloors = 3;
	static const int buildingColumns = 3;

	static const int maxDeadCivs = 3;

	static const float truckHeight= 100;
	static const float truckWidth = 250;
	static const Color truckColor = RED;

	static const float ambulanceHeight = 100;
	static const float ambulanceWidth = 250;

	gameplay::gameplay() {
		_gameplayOn = false;
		_toMenu = false;
		_toCredits = false;
		_truck = new truck(truckHeight,truckWidth, screenWidth/2, screenHeight-(screenHeight/5));
		_building = new building(buildingHeight,buildingWidth, screenWidth/2 -(buildingWidth/2), screenHeight/7, buildingFloors, buildingColumns );
		_hydrant = new Hydrant(screenWidth / 5, screenHeight - (screenHeight / 4));
		_ambulanceLeft = new Ambulance(ambulanceHeight,ambulanceWidth,screenWidth/10,screenHeight-(screenHeight/5));
		_ambulanceRight = new Ambulance(ambulanceHeight, ambulanceWidth,screenWidth - screenWidth / 10, screenHeight - (screenHeight / 5));
		_deadCivs = 0;
		Image background = LoadImage("res/assets/img/FondoNivel1.jpg");
		ImageResize(&background,1920,1080);
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
		DrawTexture(_background, 0, 0, RAYWHITE);
		_building->draw();
		_truck->draw();
		_hydrant->draw();
		_ambulanceLeft->draw();
		_ambulanceRight->draw();
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

	void gameplay::checkCivilianSave() {
		for (int i = 0; i < (buildingColumns*buildingFloors); i++){
			if (CheckCollisionRecs(_ambulanceLeft->getBody(),_building->getCivilianBody(i))) {
				if (!_building->getCivIsSaved(i)) {
					_building->saveCivilians(i);
				};
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