#include "truck.h"

#include "Sprites/truck_sprites.h"
#include "Sprites/water_sprites.h"
#include "System/screen.h"
#include "Music/truck_sfx.h"

using namespace SummerLab;

namespace SummerLab {

	const Color waterColor = DARKBLUE;
	const float maxWaterTank = 100;
	const float waterShotWidth = 20;
	const float waterShotsXOffset = 89;
	const float waterShotsYOffset = 613;	static const float maxWaterY = 165;
	const float pressureChargeRate = 200;
	const float pressureDischargeRate = 180;
	const float tankDrainRate = 5;
	const float tankRechargeRate = 20;

	const float truckSpeed = 500;
	const float gamepadTruckSpeed = 2000;
	
	const Color truckColor = RED;

	static const float trampYOffset = 50;
	static const float trampXOffset = 17;
	const Color trampColor = DARKGREEN;

	static float trampolineXHitboxWidth;

	static const float maxTimerFrame = 0.2f;
	static const int maxFramesWater = 3;

	static const float maxTimerSiren = 0.15f;
	static bool sirenShining = false;

	truck::truck(float height, float width, float posX, float posY) {
		_body.height = height;
		_body.width = width;
		_body.x = posX;
		_body.y = posY;
		_color = truckColor;
		_waterTank = maxWaterTank;
		_pressure = 0;
		_waterShotLine.height = 0;
		_waterShotLine.width = waterShotWidth;
		_waterShotLine.x = posX + (width / 3) - 7;
		_waterShotLine.y = posY;
		_trampoline.height = height / 10;
		_trampoline.width = width / 2;
		_trampoline.x = (posX + width) - _trampoline.width - trampXOffset;
		_trampoline.y = posY + trampYOffset;
		trampolineXHitboxWidth = width / 6;
		_trampColor = trampColor;
		_bounceOnce = false;
		_isOnMenu = false;
		_timerFrame = 0.0f;
		_numFrame = 0;
		_timerSiren = 0;

		for (int i = 0; i < 5; i++) {
			_truckSprites[i] = truckSprite[i];
		}		_sirenSprite = sirenSprite;

		for (int i = 0; i < 5; i++) {
			_menuTruckSprites[i] = menuTruckSprite[i];
		}		_menuSirenSprite = menuSirenSprite;

		for (int i = 0; i < maxFramesWater; i++) {
			_waterShot1[i] = waterShot1Sprite[i];
			_waterShot2[i] = waterShot2Sprite[i];
			_waterShot3[i] = waterShot3Sprite[i];
			_waterShot4[i] = waterShot4Sprite[i];
			_waterShot5[i] = waterShot5Sprite[i];
			_waterShot6[i] = waterShot6Sprite[i];
			_waterShot7[i] = waterShot7Sprite[i];
		}
		_motorOn = motorOn;
		_motorOff = motorOff;
		_motorLoop = motorLoop;
		_waterShot = waterShot;
		_truckSiren = truckSiren;
	}

	truck::~truck() {
		/*for (int i = 0; i < 5; i++) {
			UnloadTexture(_truckSprites[i]);
		}*/
	}

	void truck::setBodyHeight(float height) {
		_body.height = height;
	}
	void truck::setBodyWidth(float width) {
		_body.width = width;
	}
	void truck::setBodyX(float x) {
		_body.x = x;
	}
	void truck::setBodyY(float y) {
		_body.y = y;
	}
	void truck::setWaterTank(float waterTank) {
		_waterTank = waterTank;
	}
	void truck::setPressure(float pressure) {
		_pressure = pressure;
	}
	void truck::setWaterShotX(float x) {
		_waterShotLine.x = x;
	}
	void truck::setWaterShotY(float y) {
		_waterShotLine.y = y;
	}
	void truck::setWaterShotWidth(float width) {
		_waterShotLine.width = width;
	}

	void truck::setIsOnMenu(bool isOnMenu) {
		_isOnMenu = isOnMenu;
	}

	Rectangle truck::getWaterShot() {
		return _waterShotLine;
	}

	float truck::getBodyHeight() {
		return _body.height;
	}
	float truck::getBodyWidth() {
		return _body.width;
	}
	float truck::getBodyX() {
		return _body.x;
	}
	float truck::getBodyY() {
		return _body.y;
	}
	float truck::getWaterTank() {
		return _waterTank;
	}
	float truck::getPressure() {
		return _pressure;
	}
	float truck::getWaterShotX() {
		return _waterShotLine.x;
	}
	float truck::getWaterShotY() {
		return _waterShotLine.y;
	}
	float truck::getWaterShotWidth() {
		return _waterShotLine.width;
	}

	void truck::move() {
		float time = GetFrameTime();
		if (!_isOnMenu && IsKeyDown(KEY_LEFT) && _body.x > screenWidth / 4) {
			_body.x -= truckSpeed * time;
			_waterShotLine.x -= (truckSpeed * time);
			_trampoline.x -= (truckSpeed * time);

		}
		if (!_isOnMenu && IsKeyDown(KEY_RIGHT) && _body.x + _body.width < screenWidth - screenWidth / 4) {
			_body.x += truckSpeed * time;
			_waterShotLine.x += (truckSpeed * time);
			_trampoline.x += (truckSpeed * time);
		}
		if (_isOnMenu && IsKeyDown(KEY_LEFT) && _body.x > screenWidth / 3) {
			_body.x -= truckSpeed * time;
			_waterShotLine.x -= (truckSpeed * time);
			_trampoline.x -= (truckSpeed * time);

		}
		if (_isOnMenu && IsKeyDown(KEY_RIGHT) && _body.x + _body.width < screenWidth + _body.width / 2) {
			_body.x += truckSpeed * time;
			_waterShotLine.x += (truckSpeed * time);
			_trampoline.x += (truckSpeed * time);
		}

		if (!_isOnMenu && _body.x >= screenWidth / 4 && _body.x + _body.width <= screenWidth - screenWidth / 4) {
			float axisMovementL = GetGamepadAxisMovement(GAMEPAD_PLAYER1, GAMEPAD_AXIS_LEFT_X);
			float axisMovementR = GetGamepadAxisMovement(GAMEPAD_PLAYER1, GAMEPAD_AXIS_RIGHT_X);

			_body.x -= axisMovementL * gamepadTruckSpeed * time;
			_body.x -= axisMovementR * gamepadTruckSpeed * time;
			_waterShotLine.x -= axisMovementL * gamepadTruckSpeed* time;
			_waterShotLine.x -= axisMovementR * gamepadTruckSpeed* time;
			_trampoline.x -= axisMovementL * gamepadTruckSpeed* time;
			_trampoline.x -= axisMovementR * gamepadTruckSpeed* time;

		}
		else if (!_isOnMenu && _body.x < screenWidth / 4) {
			_body.x = (screenWidth / 4) + 5;
			_trampoline.x = _body.x + _trampoline.width - trampXOffset;
			_waterShotLine.x = _body.x + (_body.width / 3) - 7;
		}
		else if (!_isOnMenu && _body.x > screenWidth / 4) {
			_body.x = screenWidth - (screenWidth / 4) - _body.width - 5;
			_trampoline.x = _body.x + _trampoline.width - trampXOffset;
			_waterShotLine.x = _body.x + (_body.width / 3) - 7;
		}

		if (!IsSoundPlaying(motorLoop)) {
			PlaySound(motorLoop);
		}
	}

	void truck::shoot() {
		float time = GetFrameTime();
		if (IsKeyDown(KEY_UP) && _waterTank > 0 && _waterShotLine.y > maxWaterY) {
			if (_waterShotLine.y > _body.y - 630) {
				_pressure += pressureChargeRate * time;
				_waterShotLine.y -= pressureChargeRate * time;
				if (!IsSoundPlaying(waterShot)) {
					PlaySound(waterShot);
				}
			}
			_waterTank -= tankDrainRate * time;
		}		else if (IsGamepadButtonPressed(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) && _waterTank > 0 && _waterShotLine.y > maxWaterY) {
			_pressure += 30000 * time;
			_waterShotLine.y -= 30000 * time;
			_waterTank -= tankDrainRate * time;
		}

		if ((_pressure > 0 && !IsKeyDown(KEY_UP)) ||
			(_pressure > 0 && _waterTank <= 0)) {
			_pressure -= pressureDischargeRate * time;
			_waterShotLine.y += pressureDischargeRate * time;
		}

		if (_pressure <= 0 && IsSoundPlaying(waterShot)) {
			StopSound(waterShot);
		}
		_waterShotLine.height = _pressure;
	}

	void truck::recharge(Rectangle rec) {
		float time = GetFrameTime();
		if (CheckCollisionRecs(_body, rec) && IsKeyDown(KEY_DOWN)) {
			_waterTank += tankRechargeRate * time;
		}
	}

	BounceDirection truck::checkBounce(Rectangle rec) {
		int random = GetRandomValue(0, 3);
		if (CheckCollisionRecs(rec, _trampoline) && (rec.x + rec.width / 2 > _trampoline.x - rec.width / 2 && rec.x + rec.width / 2 < _trampoline.x + trampolineXHitboxWidth)) {
			return bLeft;
			if (!IsSoundPlaying(trampolineSound[random])) {
				PlaySound(trampolineSound[random]);
			}
		}
		else if (CheckCollisionRecs(rec, _trampoline) && (rec.x + rec.width / 2 >= _trampoline.x + trampolineXHitboxWidth && rec.x + rec.width / 2 <= _trampoline.x + (trampolineXHitboxWidth * 2))) {
			return bUp;
			if (!IsSoundPlaying(trampolineSound[random])) {
				PlaySound(trampolineSound[random]);
			}
		}
		else if (CheckCollisionRecs(rec, _trampoline) && (rec.x + rec.width / 2 > _trampoline.x + (trampolineXHitboxWidth * 2) && rec.x + rec.width / 2 <= _trampoline.x + _trampoline.width + rec.width / 2)) {
			return bRight;
			if (!IsSoundPlaying(trampolineSound[random])) {
				PlaySound(trampolineSound[random]);
			}
		}
		else {
			return bNone;
		}
	}

	void truck::draw() {
		if (!_isOnMenu) {
			if (_waterTank <= 25) {
				DrawTexture(_truckSprites[0], _body.x, _body.y, RAYWHITE);			}
			else if (_waterTank > 25 && _waterTank <= 50) {
				DrawTexture(_truckSprites[1], _body.x, _body.y, RAYWHITE);			}
			else if (_waterTank > 50 && _waterTank <= 75) {
				DrawTexture(_truckSprites[2], _body.x, _body.y, RAYWHITE);			}
			else if (_waterTank > 75 && _waterTank < 100) {
				DrawTexture(_truckSprites[3], _body.x, _body.y, RAYWHITE);			}
			else {
				DrawTexture(_truckSprites[4], _body.x, _body.y, RAYWHITE);
			}
		}

		if (_isOnMenu) {
			if (_waterTank <= 25) {
				DrawTexture(_menuTruckSprites[0], _body.x, _body.y, RAYWHITE);			}
			else if (_waterTank > 25 && _waterTank <= 50) {
				DrawTexture(_menuTruckSprites[1], _body.x, _body.y, RAYWHITE);			}
			else if (_waterTank > 50 && _waterTank <= 75) {
				DrawTexture(_menuTruckSprites[2], _body.x, _body.y, RAYWHITE);			}
			else if (_waterTank > 75 && _waterTank < 100) {
				DrawTexture(_menuTruckSprites[3], _body.x, _body.y, RAYWHITE);			}
			else {
				DrawTexture(_menuTruckSprites[4], _body.x, _body.y, RAYWHITE);
			}
		}

		_timerSiren += GetFrameTime();
		if (_timerSiren >= maxTimerSiren) {
			_timerSiren = 0;
			if (sirenShining == true)
				sirenShining = false;
			else if (sirenShining == false)
				sirenShining = true;
		}

		if (!_isOnMenu) {
			if (sirenShining == true) {
				DrawTexture(_sirenSprite, _body.x, _body.y, RAYWHITE);
				if (!IsSoundPlaying(truckSiren)) {
					PlaySound(truckSiren);
				}
			}
		}

		if (_isOnMenu) {
			if (sirenShining == true) {
				DrawTexture(_menuSirenSprite, _body.x, _body.y, RAYWHITE);
				if (!IsSoundPlaying(truckSiren)) {
					PlaySound(truckSiren);
				}
			}
		}

		_timerFrame += GetFrameTime();
		if (_timerFrame >= maxTimerFrame) {
			_timerFrame = 0;
			_numFrame++;
			if (_numFrame >= maxFramesWater) {
				_numFrame = 0;
			}
		}

		if (_waterShotLine.y <= _body.y - 20 &&
			_waterShotLine.y > _body.y - 140) {
			DrawTexture(_waterShot1[_numFrame], _waterShotLine.x - waterShotsXOffset, _body.y - waterShotsYOffset, RAYWHITE);
		}
		if (_waterShotLine.y <= _body.y - 140 &&
			_waterShotLine.y > _body.y - 260) {
			DrawTexture(_waterShot2[_numFrame], _waterShotLine.x - waterShotsXOffset, _body.y - waterShotsYOffset, RAYWHITE);
		}
		if (_waterShotLine.y <= _body.y - 260 &&
			_waterShotLine.y > _body.y - 300) {
			DrawTexture(_waterShot3[_numFrame], _waterShotLine.x - waterShotsXOffset, _body.y - waterShotsYOffset, RAYWHITE);
		}
		if (_waterShotLine.y <= _body.y - 300 &&
			_waterShotLine.y > _body.y - 400) {
			DrawTexture(_waterShot4[_numFrame], _waterShotLine.x - waterShotsXOffset, _body.y - waterShotsYOffset, RAYWHITE);
		}
		if (_waterShotLine.y <= _body.y - 400 &&
			_waterShotLine.y > _body.y - 450) {
			DrawTexture(_waterShot5[_numFrame], _waterShotLine.x - waterShotsXOffset, _body.y - waterShotsYOffset, RAYWHITE);
		}
		if (_waterShotLine.y <= _body.y - 450 &&
			_waterShotLine.y > _body.y - 520) {
			DrawTexture(_waterShot6[_numFrame], _waterShotLine.x - waterShotsXOffset, _body.y - waterShotsYOffset, RAYWHITE);
		}
		if (_waterShotLine.y <= _body.y - 520 &&
			_waterShotLine.y > _body.y - 630) {
			DrawTexture(_waterShot7[_numFrame], _waterShotLine.x - waterShotsXOffset, _body.y - waterShotsYOffset, RAYWHITE);
		}
		DrawRectangleRec(_waterShotLine, waterColor);
	}
}