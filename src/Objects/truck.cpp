#include "truck.h"

#include "Sprites/truck_sprites.h"
#include "Sprites/water_sprites.h"

using namespace SummerLab;

namespace SummerLab {

	const Color waterColor = DARKBLUE;

	const float maxWaterTank = 100;
	const float waterShotWidth = 10;
	const float waterShot1XOffset = 60;
	const float waterShotsXOffset = 122;
	const float waterShot1YOffset = 145;
	const float waterShot2YOffset = 273;
	const float waterShot3YOffset = 348;
	const float waterShot4YOffset = 409;
	const float waterShot5YOffset = 476;
	const float waterShot6YOffset = 546;
	const float waterShot7YOffset = 637;

	const float pressureChargeRate = 200;
	const float pressureDischargeRate = 180;
	const float tankDrainRate = 5;
	const float tankRechargeRate = 10;

	const float truckSpeed = 500;

	const Color truckColor = RED;

	static const float trampYOffset = 50;
	static const float trampXOffset = 17;
	const Color trampColor = DARKGREEN;

	static float trampolineXHitboxWidth;

	truck::truck(float height, float width, float posX, float posY) {
		_body.height = height;
		_body.width = width;
		_body.x = posX;
		_body.y = posY;
		trampolineXHitboxWidth = width / 3;
		_color = truckColor;
		_waterTank = maxWaterTank;
		_pressure = 0;
		_waterShotLine.height = 0;
		_waterShotLine.width = waterShotWidth;
		_waterShotLine.x = posX + (width / 3);
		_waterShotLine.y = posY;
		_waterShotSpread.height = 0;
		_waterShotSpread.width = waterShotWidth;
		_waterShotSpread.x = 0;
		_trampoline.height = height / 10;
		_trampoline.width = width / 2;
		_trampoline.x = (posX + width) - _trampoline.width-trampXOffset;
		_trampoline.y = posY + trampYOffset;
		_trampColor = trampColor;
		_bounceOnce = false;
		
		for (int i = 0; i < 5; i++) {
			_truckSprites[i] = truckSprite[i];
		}

		for (int i = 0; i < 3; i++) {
			_waterShot1[i] = waterShot1Sprite[i];
			_waterShot2[i] = waterShot2Sprite[i];
			_waterShot3[i] = waterShot3Sprite[i];
			_waterShot4[i] = waterShot4Sprite[i];
			_waterShot5[i] = waterShot5Sprite[i];
			_waterShot6[i] = waterShot6Sprite[i];
			_waterShot7[i] = waterShot7Sprite[i];
		}
	}

	truck::~truck() {

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
		if (IsKeyDown(KEY_LEFT)) {
			_body.x -= truckSpeed * time;
			_waterShotLine.x -= (truckSpeed * time);
			_trampoline.x -= (truckSpeed * time);
		}
		if (IsKeyDown(KEY_RIGHT)) {
			_body.x += truckSpeed * time;
			_waterShotLine.x += (truckSpeed * time);
			_trampoline.x += (truckSpeed * time);
		}
	}

	void truck::shoot() {
		float time = GetFrameTime();
		if (IsKeyDown(KEY_UP) && _waterTank > 0) {
			_pressure += pressureChargeRate * time;
			_waterShotLine.y -= pressureChargeRate * time;
			_waterTank -= tankDrainRate * time;
		}
		if ((_pressure > 0 && !IsKeyDown(KEY_UP)) ||
			(_pressure > 0 && _waterTank <= 0)) {
			_pressure -= pressureDischargeRate * time;
			_waterShotLine.y += pressureDischargeRate * time;
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
		if (CheckCollisionRecs(rec, _trampoline) && (rec.x > _trampoline.x -rec.width && rec.x < _trampoline.x + trampolineXHitboxWidth)) {
			return bLeft;
		}
		else if (CheckCollisionRecs(rec, _trampoline) && (rec.x >= _trampoline.x + trampolineXHitboxWidth && rec.x < _trampoline.x + (trampolineXHitboxWidth * 2))) {
			return bUp;
		}
		else if (CheckCollisionRecs(rec, _trampoline) && (rec.x > _trampoline.x + (trampolineXHitboxWidth * 2))) {
			return bRight;
		}
		else {
			return bNone;
		}
	}

	void truck::draw() {
		DrawRectangleRec(_body,_color);
		DrawRectangleRec(_trampoline, _trampColor);
	
		if (_waterTank <= 25)
			DrawTexture(_truckSprites[0], _body.x, _body.y, RAYWHITE);
		else if (_waterTank > 25 && _waterTank <= 50)
			DrawTexture(_truckSprites[1], _body.x, _body.y, RAYWHITE);
		else if (_waterTank > 50 && _waterTank <= 75)
			DrawTexture(_truckSprites[2], _body.x, _body.y, RAYWHITE);
		else if (_waterTank > 75 && _waterTank < 100)
			DrawTexture(_truckSprites[3], _body.x, _body.y, RAYWHITE);
		else
			DrawTexture(_truckSprites[4], _body.x, _body.y, RAYWHITE);

		if (_waterShotLine.y <= _body.y-20 &&
			_waterShotLine.y > _body.y-140) {
			DrawTexture(_waterShot1[0], _waterShotLine.x - waterShot1XOffset, _body.y - waterShot1YOffset, RAYWHITE);
		}
		if (_waterShotLine.y <= _body.y - 140 &&
			_waterShotLine.y > _body.y - 260) {
			DrawTexture(_waterShot2[0], _waterShotLine.x - waterShotsXOffset, _body.y - waterShot2YOffset, RAYWHITE);
		}
		if (_waterShotLine.y <= _body.y - 260 &&
			_waterShotLine.y > _body.y - 330) {
			DrawTexture(_waterShot3[0], _waterShotLine.x - waterShotsXOffset, _body.y - waterShot3YOffset, RAYWHITE);
		}
		if (_waterShotLine.y <= _body.y - 330 &&
			_waterShotLine.y > _body.y - 400) {
			DrawTexture(_waterShot4[0], _waterShotLine.x - waterShotsXOffset, _body.y - waterShot4YOffset, RAYWHITE);
		}
		if (_waterShotLine.y <= _body.y - 400 &&
			_waterShotLine.y > _body.y - 470) {
			DrawTexture(_waterShot5[0], _waterShotLine.x - waterShotsXOffset, _body.y - waterShot5YOffset, RAYWHITE);
		}
		if (_waterShotLine.y <= _body.y - 470 &&
			_waterShotLine.y > _body.y - 540) {
			DrawTexture(_waterShot6[0], _waterShotLine.x - waterShotsXOffset, _body.y - waterShot6YOffset, RAYWHITE);
		}
		if (_waterShotLine.y <= _body.y - 540 &&
			_waterShotLine.y > _body.y - 630) {
			DrawTexture(_waterShot7[0], _waterShotLine.x - waterShotsXOffset, _body.y - waterShot7YOffset, RAYWHITE);
		}
		DrawRectangleRec(_waterShotLine, waterColor);
	}
}