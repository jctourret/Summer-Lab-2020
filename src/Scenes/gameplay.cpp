#include "gameplay.h"

#include "raylib.h"

#include "System/screen.h"

using namespace SummerLab;

namespace SummerLab {

	static const float buildingHeight = 700.0f;
	static const float buildingWidth = 500.0f;
	static const int buildingFloors = 3;
	static const int buildingColumns = 3;

	static const int maxDeadCivs = 3;

	static const float truckHeight= 212.0f;
	static const float truckWidth = 357.0f;
	static const Color truckColor = RED;

	static const float ambulanceHeight = 175;
	static const float ambulanceWidth = 342;

	static float gameTimer = 0.0f;
	static const float maxGameTime = 60.0f*1;

	gameplay::gameplay() {
		_gameplayOn = false;
		_toMenu = false;
		_toCredits = false;
		_gameWon = false;
		_truck = new truck(truckHeight,truckWidth, screenWidth/2, screenHeight-(screenHeight/9)-truckHeight);
		_building = new building(buildingHeight,buildingWidth, screenWidth/2 -(buildingWidth/2), screenHeight/7, buildingFloors, buildingColumns );
		_hydrant = new Hydrant(screenWidth / 3-70, screenHeight - (screenHeight / 4)-15);
		_ambulanceLeft = new Ambulance(ambulanceHeight,ambulanceWidth, screenWidth/15, screenHeight - (screenHeight / 9) - ambulanceHeight);
		_ambulanceRight = new Ambulance(ambulanceHeight, ambulanceWidth, screenWidth - screenWidth / 15 - ambulanceWidth, screenHeight - (screenHeight / 9) - ambulanceHeight);
		_deadCivs = 0;
		Image background = LoadImage("res/assets/img/FondoNivel1.jpg");
		ImageResize(&background,1920,1080);
		_background = LoadTextureFromImage(background);
		UnloadImage(background);
		Image barricade = LoadImage("res/assets/img/barricade.png");
		ImageResize(&barricade, 1920, 1080);
		_barricade = LoadTextureFromImage(barricade);
		UnloadImage(barricade);
		Image gameOverBurn = LoadImage("res/assets/img/gameOver/gameOverBurn.png");
		ImageResize(&gameOverBurn, 1920, 1080);
		_gameOverBurn = LoadTextureFromImage(gameOverBurn);
		UnloadImage(gameOverBurn);
		Image gameOverDead = LoadImage("res/assets/img/gameOver/gameOverDead.png");
		ImageResize(&gameOverDead, 1920, 1080);
		_gameOverDead = LoadTextureFromImage(gameOverDead);
		UnloadImage(gameOverDead);
		Image gameOverWin = LoadImage("res/assets/img/gameOver/gameOverWin.png");
		ImageResize(&gameOverWin, 1920, 1080);
		_gameOverWin = LoadTextureFromImage(gameOverWin);
		UnloadImage(gameOverWin);
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

	bool gameplay::getGameWon() {
		return _gameWon;
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
			_toMenu = true;
		}
		if (_gameplayOn && !_gameWon) {
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
			checkCivilianSaved();
			runGameTimer(gameTimer);
		}
		gameResult();
	}

	void gameplay::draw() {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexture(_background, 0, 0, RAYWHITE);
		_hydrant->draw();
		_ambulanceLeft->draw();
		_ambulanceRight->draw();
		DrawTexture(_barricade, 0, 0, RAYWHITE);
		_building->draw();
		_truck->draw();
		if (_gameWon && !_gameplayOn) {
			DrawTexture(_gameOverWin, 0, 0, RAYWHITE);
		}
		if (!_gameWon && !_gameplayOn && _building->countLargeFires() == _building->getColumns()*_building->getFloors()) {
			DrawTexture(_gameOverBurn, 0, 0, RAYWHITE);
		}
		if (!_gameWon && !_gameplayOn && _deadCivs > maxDeadCivs) {
			DrawTexture(_gameOverDead, 0, 0, RAYWHITE);
		}
		EndDrawing();
	}

	void gameplay::checkCiviliansBounce() {
		for (int i = 0; i < (buildingColumns*buildingFloors); i++){
			BounceDirection bDir = _truck->checkBounce(_building->getCivilianBody(i));
			if (bDir == bLeft) {
				_building->setCivBounceDirection(i, cLeft);
				_building->resetCivBounce(i);
			}
			if (bDir == bUp) {
				_building->setCivBounceDirection(i, cUp);
				_building->resetCivBounce(i);
			}
			if (bDir == bRight) {
				_building->setCivBounceDirection(i, cRight);
				_building->resetCivBounce(i);
			}
		}
	}

	void gameplay::checkCivilianSaved() {
		for (int i = 0; i < (buildingColumns*buildingFloors); i++){
			if (CheckCollisionRecs(_ambulanceLeft->getBody(),_building->getCivilianBody(i))) {
				if (!_building->getCivIsSaved(i)) {
					_building->saveCivilians(i);
				};
			}
			if (CheckCollisionRecs(_ambulanceRight->getBody(), _building->getCivilianBody(i))) {
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

	void gameplay::runGameTimer(float timer) {
		timer += GetFrameTime();
		if (timer >= maxGameTime) {
			_gameplayOn = false;
			_gameWon = true;
		}
	}

	void gameplay::gameResult() {
		if (_deadCivs >= maxDeadCivs || _building->countLargeFires() == _building->getColumns()*_building->getFloors()) {
			_gameplayOn = false;
			_gameWon = false;
		}
	}

}