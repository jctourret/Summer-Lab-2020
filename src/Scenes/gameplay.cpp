#include "gameplay.h"

#include "raylib.h"

#include "System/screen.h"
#include "Sprites/background_sprites.h"
#include "Music/fire_sfx.h"
#include "Music/music.h"
#include "Music/truck_sfx.h"

using namespace SummerLab;

#include <iostream>
using namespace std;

namespace SummerLab {

	static const float buildingHeight = 700.0f;
	static const float buildingWidth = 500.0f;
	static const int buildingFloors = 3;
	static const int buildingColumns = 3;

	static const int maxDeadCivs = 3;

	static const float truckHeight = 212.0f;
	static const float truckWidth = 357.0f;
	static const Color truckColor = RED;

	static const float ambulanceHeight = 175;
	static const float ambulanceWidth = 342;

	static float gameTimer = 0.0f;
	static const float maxGameTime = 120.0f;

	static float timerBackMenu = 0.0f;
	static const float maxTimeBackMenu = 10.0f;

	static float collapseTimer = 0.0f;
	static const float collapseFrameTime = 0.075f;
	static int actualCollapseFrame = 0;
	static const int maxCollapseFrame = 15;
	static bool destroyBuilding = false;

	static bool playCollapseOnce = true;

	static const float skyTime = 2800.0f;
	static const float maxSkyPosition = 7670;
	static float sky1PositionX = 0;
	static float sky2PositionX = maxSkyPosition;

	static const float resetSunX = 1500;
	static float sunPositionX = 0;
	static float clouds1Position = 0;
	static float clouds2Position = 2050;
	static const float maxCloudPosition = 2880;

	static const float skySpeed = 52.5f;
	static const float cloudsSpeed = 45.0f;
	static const float sunSpeed = 16.0f;
	static Time time = day;
	static bool deadExtraMessage = false;

	static float timeDay = 0.0f;
	static float timeAfternoon = 0.0f;
	static float timeNight = 0.0f;

	static const float maxTimeDay = 24.5f;
	static const float maxTimeAfertnoon = 24.5f;
	static const float maxTimeNight = 21.5f;
	static bool dayToNight = true;
	static bool firstRotation = true;

	gameplay::gameplay() {
		_gameplayOn = true;
		_toMenu = false;
		_toCredits = false;
		_gameWon = false;
		_gameLost = false;
		_playMotorOffOnce = true;
		_playMotorOnOnce = true;
		_playCollapseOnce = true;
		_buildingLittlyDamaged = false;
		_buildingModeratelyDamaged = false;
		_buildingDamaged = false;
		_buildingVeryDamaged = false;
		_buildingSeverelyDamaged = false;
		_truck = new truck(truckHeight, truckWidth, screenWidth / 2, screenHeight - (screenHeight / 9) - truckHeight);
		_building = new building(buildingHeight, buildingWidth, screenWidth / 2 - (buildingWidth / 2), screenHeight / 7, buildingFloors, buildingColumns);
		_hydrant = new Hydrant(screenWidth / 3 - 70, screenHeight - (screenHeight / 4) - 15);
		_ambulanceLeft = new Ambulance(ambulanceHeight, ambulanceWidth, screenWidth / 15, screenHeight - (screenHeight / 9) - ambulanceHeight);
		_ambulanceRight = new Ambulance(ambulanceHeight, ambulanceWidth, screenWidth - screenWidth / 15 - ambulanceWidth, screenHeight - (screenHeight / 9) - ambulanceHeight);
		_deadCivs = 0;
		gameTimer = 0.0f;
		timerBackMenu = 0.0f;
		collapseTimer = 0.0f;
		actualCollapseFrame = 0;
		destroyBuilding = false;
		sunPositionX = 0;
		sky1PositionX = 0;
		clouds1Position = 0;
		clouds2Position = 2050;
		sky2PositionX = maxSkyPosition;
		time = day;
		timeDay = 0.0f;
		timeAfternoon = 0.0f;
		timeNight = 0.0f;
		dayToNight = true;

		_deadCivs = 0;
		gameTimer = 0.0f;
		timerBackMenu = 0.0f;
		collapseTimer = 0.0f;
		actualCollapseFrame = 0;
		destroyBuilding = false;
		playCollapseOnce = true;
		sky1PositionX = 0;
		sky2PositionX = maxSkyPosition;
		sunPositionX = 0;
		clouds1Position = 0;
		clouds2Position = 2050;
		time = day;
		deadExtraMessage = false;
		timeDay = 0.0f;
		timeAfternoon = 0.0f;
		timeNight = 0.0f;
		dayToNight = true;
		firstRotation = true;


		for (int i = 0; i < 8; i++) {
			_background[i] = backgroundSprites[i];
		}

		for (int i = 0; i < 6; i++) {
			_skiesSprites[i] = skiesSprites[i];
		}

		for (int i = 0; i < 3; i++) {
			_gameOverBurn[i] = gameOverBurnSprite[i];
			_gameOverDead[i] = gameOverDeadSprite[i];
			_gameOverDeadExtra[i] = gameOverDeadExtraSprite[i];
			_gameOverWin[i] = gameOverWinSprite[i];
		}

		for (int i = 0; i < 3; i++) {
			_killCount[i] = killCountSprites[i];
		}

		for (int i = 0; i < 5; i++) {
			_buildingCracks[i] = buildingCracks[i];
		}

		for (int i = 0; i < 16; i++) {
			_buildingCollapsing[i] = buildingCollapsing[i];
		}
	}

	gameplay::~gameplay() {/*
		delete _truck;
		delete _building;
		delete _hydrant;
		delete _ambulanceLeft;
		delete _ambulanceRight;

		UnloadTexture(_background);
		UnloadTexture(_barricade);
		UnloadTexture(_gameOverBurn);
		UnloadTexture(_gameOverDead);
		UnloadTexture(_gameOverWin);*/
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

		if (_gameWon == false && _gameLost == false) {
			if (!IsSoundPlaying(motorOn) && _playMotorOnOnce) {
				PlaySound(motorOn);
				_playMotorOnOnce = false;
			}
			_building->initFire();
			_building->growFireTimers();
			_building->dozeFireTimers(_truck->getWaterShot());
			_building->spreadFireTimers();
			_building->playFire();
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
			gameResult();
		}
		else if (_gameWon == true || _gameLost == true) {
			timerBackMenu += GetFrameTime();
			if (timerBackMenu >= maxTimeBackMenu) {
				timerBackMenu = 0;
				_gameplayOn = false;
				_toMenu = true;
				if (!IsSoundPlaying && _playMotorOffOnce) {
					PlaySound(motorOff);
					_playMotorOffOnce = false;
				}
			}
		}
		playMainTheme();
	}

	void gameplay::draw() {
		BeginDrawing();
		ClearBackground(BLACK);

		if (_gameWon == false && _gameLost == false) {
			sky1PositionX -= skySpeed * GetFrameTime();
			if (sky1PositionX <= -maxSkyPosition)
				sky1PositionX = maxSkyPosition;

			sky2PositionX -= skySpeed * GetFrameTime();
			if (sky2PositionX <= -maxSkyPosition)
				sky2PositionX = maxSkyPosition;

			if (time == day || time == afternoon) {
				sunPositionX -= sunSpeed * GetFrameTime();
				//sunPositionX -= (screenWdith / maxGameTimer) * GetFrameTime();
			}

			if (time == day) {
				timeDay += GetFrameTime();
				if (timeDay >= maxTimeDay) {
					if (dayToNight == true)
						time = afternoon;
					timeDay = 0;
					dayToNight = true;
				}
			}
			else if (time == afternoon) {
				timeAfternoon += GetFrameTime();
				if (timeAfternoon >= maxTimeAfertnoon) {
					if (dayToNight == true)
						time = night;
					else if (dayToNight == false)
						time = day;

					timeAfternoon = 0;
				}
			}
			else if (time == night) {
				timeNight += GetFrameTime();
				if (timeNight >= maxTimeNight) {
					if (dayToNight == false)
						time = afternoon;
					timeNight = 0;
					dayToNight = false;
				}
			}
		}

		if (time == night) {
			sunPositionX = resetSunX;
		}

		DrawTexture(_skiesSprites[sky1], sky1PositionX, 0, RAYWHITE);
		DrawTexture(_skiesSprites[sky2], sky2PositionX, 0, RAYWHITE);
		if (time == day || time == afternoon) {
			DrawTexture(_skiesSprites[sun], sunPositionX, 0, RAYWHITE);
			DrawTexture(_skiesSprites[sunlights], sunPositionX, 0, RAYWHITE);
		}

		if (clouds1Position >= -maxCloudPosition || clouds2Position >= -maxCloudPosition) {
			clouds1Position -= cloudsSpeed * GetFrameTime();
			clouds2Position -= cloudsSpeed * GetFrameTime();
			DrawTexture(_skiesSprites[clouds1], clouds1Position, 0, RAYWHITE);
			DrawTexture(_skiesSprites[clouds2], clouds2Position, 0, RAYWHITE);
		}

		if (time == day)
			DrawTexture(_background[buldingsBGDay], 0, 0, RAYWHITE);
		else if (time == afternoon)
			DrawTexture(_background[buildingsBGAfternoon], 0, 0, RAYWHITE);
		else if (time == night)
			DrawTexture(_background[buildingsBGNight], 0, 0, RAYWHITE);


		if (destroyBuilding == false) {
			DrawTexture(_background[buildingP], 0, 0, RAYWHITE);

			if ((_building->countSmallFires() >= 4 ||
				_building->countMediumFires() >= 2 ||
				_building->countLargeFires() >= 1) ||
				_buildingLittlyDamaged == true) {
				DrawTexture(_buildingCracks[0], 0, 0, RAYWHITE);
				_buildingLittlyDamaged = true;
			}
			if ((_building->countSmallFires() >= 6 ||
				_building->countMediumFires() >= 4 ||
				_building->countLargeFires() >= 2) ||
				_buildingModeratelyDamaged == true) {
				DrawTexture(_buildingCracks[1], 0, 0, RAYWHITE);
				_buildingModeratelyDamaged = true;
			}
			if ((_building->countSmallFires() >= 9 ||
				_building->countMediumFires() >= 6 ||
				_building->countLargeFires() >= 3) ||
				_buildingDamaged == true) {
				DrawTexture(_buildingCracks[2], 0, 0, RAYWHITE);
				_buildingDamaged = true;
			}
			if ((_building->countSmallFires() >= 7 &&
				_building->countMediumFires() >= 2 ||
				_building->countMediumFires() >= 8 ||
				_building->countLargeFires() >= 4) ||
				_buildingVeryDamaged == true) {
				DrawTexture(_buildingCracks[3], 0, 0, RAYWHITE);
				_buildingVeryDamaged = true;
			}
			if ((_building->countSmallFires() >= 5 &&
				_building->countMediumFires() >= 4 ||
				_building->countMediumFires() >= 8 &&
				_building->countLargeFires() >= 1 ||
				_building->countLargeFires() >= 5) ||
				_buildingSeverelyDamaged == true) {
				DrawTexture(_buildingCracks[4], 0, 0, RAYWHITE);
				_buildingSeverelyDamaged = true;
			}
		}

		if (_deadCivs == oneDead) {
			DrawTexture(_killCount[oneDead], 0, 10, RAYWHITE);
		}
		else if (_deadCivs == twoDead) {
			DrawTexture(_killCount[twoDead], 0, 10, RAYWHITE);;
		}
		else if (_deadCivs == threeDead) {
			DrawTexture(_killCount[threeDead], 0, 10, RAYWHITE);
		}

		DrawTexture(_background[street], 0, 0, RAYWHITE);
		DrawTexture(_background[hydrant], 0, 0, RAYWHITE);
		DrawTexture(_background[crowd], 0, 0, RAYWHITE);
		_ambulanceLeft->draw();
		_ambulanceRight->draw();
		DrawTexture(_background[barricade], 0, 0, RAYWHITE);
		if (_gameWon == false && _gameLost == false) {
			_building->draw();
			_truck->draw();
		}

		if (_gameWon == true && _gameLost == false) {
			if (time == day)
				DrawTexture(_gameOverWin[day], 0, 0, RAYWHITE);
			else if (time == afternoon)
				DrawTexture(_gameOverWin[afternoon], 0, 0, RAYWHITE);
			else if (time == night)
				DrawTexture(_gameOverWin[night], 0, 0, RAYWHITE);
		}
		else if (_gameWon == false && _gameLost == true && _building->countLargeFires() == _building->getColumns()*_building->getFloors()) {
			DrawTexture(_buildingCollapsing[actualCollapseFrame], 0, 0, RAYWHITE);
			DrawTexture(_background[crowd], 0, 0, RAYWHITE);
			if (time == day)
				DrawTexture(_gameOverBurn[day], 0, 0, RAYWHITE);
			else if (time == afternoon)
				DrawTexture(_gameOverBurn[afternoon], 0, 0, RAYWHITE);
			else if (time == night)
				DrawTexture(_gameOverBurn[night], 0, 0, RAYWHITE);
			
			collapseTimer += GetFrameTime();
			if (collapseTimer >= collapseFrameTime && actualCollapseFrame < maxCollapseFrame) {
				collapseTimer = 0.0f;
				actualCollapseFrame++;
			}
		}
		else if (_gameWon == false && _gameLost == true && _deadCivs >= maxDeadCivs) {
			if (time == day) {
				if (deadExtraMessage == false)
					DrawTexture(_gameOverDead[day], 0, 0, RAYWHITE);
				else if (deadExtraMessage == true)
					DrawTexture(_gameOverDeadExtra[day], 0, 0, RAYWHITE);
			}
			else if (time == afternoon) {
				if (deadExtraMessage == false)
					DrawTexture(_gameOverDead[afternoon], 0, 0, RAYWHITE);
				else if (deadExtraMessage == true)
					DrawTexture(_gameOverDeadExtra[afternoon], 0, 0, RAYWHITE);
			}
			else if (time == night) {
				if (deadExtraMessage == false)
					DrawTexture(_gameOverDead[night], 0, 0, RAYWHITE);
				else if (deadExtraMessage == true)
					DrawTexture(_gameOverDeadExtra[night], 0, 0, RAYWHITE);
			}
		}
		EndDrawing();
	}

	void gameplay::checkCiviliansBounce() {
		for (int i = 0; i < (buildingColumns*buildingFloors); i++) {
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
		for (int i = 0; i < (buildingColumns*buildingFloors); i++) {
			if (CheckCollisionRecs(_ambulanceLeft->getBody(), _building->getCivilianBody(i))) {
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
		for (int i = 0; i < (buildingColumns*buildingFloors); i++) {
			_building->civBounce(i);
		}
	}

	void gameplay::checkCivilianDeath() {
		for (int i = 0; i < buildingColumns * buildingFloors; i++) {
			if (_building->getCivIsAlive(i)) {
				_building->killCivilians(i);
				if (!_building->getCivIsAlive(i)) {
					_deadCivs++;
				}
			}
		}
	}

	void gameplay::runGameTimer(float timer) {
		timer += GetFrameTime();
		if (timer >= maxGameTime) {
			_gameWon = true;
			_gameLost = false;
		}
	}

	void gameplay::gameResult() {
		if (_deadCivs >= maxDeadCivs || _building->countLargeFires() == _building->getColumns()*_building->getFloors()) {
			_gameWon = false;
			_gameLost = true;
			if (_playCollapseOnce && _building->countLargeFires() == _building->getColumns()*_building->getFloors()) {
				if (!IsSoundPlaying(buildingCollapse)) {
					PlaySound(buildingCollapse);
				}
				_playCollapseOnce = false;
				destroyBuilding = true;
			}
			if (_deadCivs >= maxDeadCivs) {
				deadExtraMessage = GetRandomValue(false, true);
			}
		}
		else if (_building->countSmallFires() == 0 && _building->countMediumFires() == 0 && _building->countLargeFires() == 0) {
			_gameWon = true;
			_gameLost = false;
		}
		else if (gameTimer >= maxGameTime) {
			_gameWon = true;
			_gameLost = false;
		}
		gameTimer += GetFrameTime();
	}

	void gameplay::playMainTheme() {
		if (!IsSoundPlaying(mainTheme)) {
			PlaySound(mainTheme);
		}
	}
}