#include "truck.h"

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

	const Color trampColor = DARKGREEN;

	truck::truck(float height, float width, float posX, float posY) {
		_body.height = height;
		_body.width = width;
		_body.x = posX;
		_body.y = posY;
		_color = truckColor;
		_waterTank = maxWaterTank;
		_pressure = 0;
		_waterShot.height = 0;
		_waterShot.width = waterShotWidth;
		_waterShot.x = posX + (width / 3);
		_waterShot.y = posY;
		_trampoline.height = height / 10;
		_trampoline.width = width / 2;
		_trampoline.x = (posX + width) - _trampoline.width;
		_trampoline.y = posY + _trampoline.height;
		_trampColor = trampColor;
		_bounceOnce = false;
		Image truck100 = LoadImage("res/assets/img/truck/Camion100.png");
		ImageResize(&truck100, width, height);
		_truck100 = LoadTextureFromImage(truck100);
		UnloadImage(truck100);
		_waterShot1a = LoadTexture("res/assets/img/water/watershot1a.png");
		_waterShot2a = LoadTexture("res/assets/img/water/watershot2a.png");
		_waterShot3a = LoadTexture("res/assets/img/water/watershot3a.png");
		_waterShot4a = LoadTexture("res/assets/img/water/watershot4a.png");
		_waterShot5a = LoadTexture("res/assets/img/water/watershot5a.png");
		_waterShot6a = LoadTexture("res/assets/img/water/watershot6a.png");
		_waterShot7a = LoadTexture("res/assets/img/water/watershot7a.png");
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
		_waterShot.x = x;
	}
	void truck::setWaterShotY(float y) {
		_waterShot.y = y;
	}
	void truck::setWaterShotWidth(float width) {
		_waterShot.width = width;
	}

	Rectangle truck::getWaterShot() {
		return _waterShot;
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
		return _waterShot.x;
	}
	float truck::getWaterShotY() {
		return _waterShot.y;
	}
	float truck::getWaterShotWidth() {
		return _waterShot.width;
	}

	void truck::move() {
		float time = GetFrameTime();
		if (IsKeyDown(KEY_LEFT)) {
			_body.x -= truckSpeed * time;
			_waterShot.x -= (truckSpeed * time);
			_trampoline.x -= (truckSpeed * time);
		}
		if (IsKeyDown(KEY_RIGHT)) {
			_body.x += truckSpeed * time;
			_waterShot.x += (truckSpeed * time);
			_trampoline.x += (truckSpeed * time);
		}
	}

	void truck::shoot() {
		float time = GetFrameTime();
		if (IsKeyDown(KEY_UP) && _waterTank > 0) {
			_pressure += pressureChargeRate * time;
			_waterShot.y -= pressureChargeRate * time;
			_waterTank -= tankDrainRate * time;
		}
		if ((_pressure > 0 && !IsKeyDown(KEY_UP)) ||
			(_pressure > 0 && _waterTank <= 0)) {
			_pressure -= pressureDischargeRate * time;
			_waterShot.y += pressureDischargeRate * time;
		}
		_waterShot.height = _pressure;
	}

	void truck::recharge(Rectangle rec) {
		float time = GetFrameTime();
		if (CheckCollisionRecs(_body, rec) && IsKeyDown(KEY_DOWN)) {
			_waterTank += tankRechargeRate * time;
		}
	}

	bool truck::checkLeftBounce(Rectangle rec) {
		if (rec.x > _trampoline.x - (rec.width) &&
			rec.x < _trampoline.x + ((_trampoline.width / 2) - rec.width) &&
			rec.y > _trampoline.y &&
			rec.y < _trampoline.y + _trampoline.height &&
			_bounceOnce == false) {
			_bounceOnce = true;
			return true;
		}
		if (!CheckCollisionRecs(_trampoline,rec)){
			_bounceOnce = false;
			return false;
		}
	}

	bool truck::checkUpBounce(Rectangle rec) {
		if (rec.x >= _trampoline.x + ((_trampoline.width / 2) + rec.width) &&
			rec.x <= _trampoline.x + ((_trampoline.width / 2) - rec.width) &&
			rec.y + rec.height > _trampoline.y &&
			rec.y + rec.height < _trampoline.y + _trampoline.height &&
			_bounceOnce == false) {
			_bounceOnce = true;
			return true;
		}
		if (!CheckCollisionRecs(_trampoline, rec)) {
			_bounceOnce = false;
			return false;
		}
	}

	bool truck::checkRightBounce(Rectangle rec) {
		if (rec.x < _trampoline.x + _trampoline.width &&
			rec.x > _trampoline.x + (_trampoline.width / 2) + rec.width &&
			rec.y + rec.height > _trampoline.y &&
			rec.y + rec.height < _trampoline.y + _trampoline.height &&
			_bounceOnce == false) {
			_bounceOnce = true;
			return true;
		}
		if (!CheckCollisionRecs(_trampoline, rec)) {
			_bounceOnce = false;
			return false;
		}
	}

	void truck::draw() {
		DrawRectangleRec(_body,_color);
		DrawTexture(_truck100, _body.x, _body.y, RAYWHITE);

		if (_waterShot.y <= _body.y-20 &&
			_waterShot.y > _body.y-140) {
			DrawTexture(_waterShot1a, _waterShot.x - waterShot1XOffset, _body.y - waterShot1YOffset, RAYWHITE);
		}
		if (_waterShot.y <= _body.y - 140 &&
			_waterShot.y > _body.y - 260) {
			DrawTexture(_waterShot2a, _waterShot.x - waterShotsXOffset, _body.y - waterShot2YOffset, RAYWHITE);
		}
		if (_waterShot.y <= _body.y - 260 &&
			_waterShot.y > _body.y - 330) {
			DrawTexture(_waterShot3a, _waterShot.x - waterShotsXOffset, _body.y - waterShot3YOffset, RAYWHITE);
		}
		if (_waterShot.y <= _body.y - 330 &&
			_waterShot.y > _body.y - 400) {
			DrawTexture(_waterShot4a, _waterShot.x - waterShotsXOffset, _body.y - waterShot4YOffset, RAYWHITE);
		}
		if (_waterShot.y <= _body.y - 400 &&
			_waterShot.y > _body.y - 470) {
			DrawTexture(_waterShot5a, _waterShot.x - waterShotsXOffset, _body.y - waterShot5YOffset, RAYWHITE);
		}
		if (_waterShot.y <= _body.y - 470 &&
			_waterShot.y > _body.y - 540) {
			DrawTexture(_waterShot6a, _waterShot.x - waterShotsXOffset, _body.y - waterShot6YOffset, RAYWHITE);
		}
		if (_waterShot.y <= _body.y - 540 &&
			_waterShot.y > _body.y - 630) {
			DrawTexture(_waterShot7a, _waterShot.x - waterShotsXOffset, _body.y - waterShot7YOffset, RAYWHITE);
		}
		DrawRectangleRec(_waterShot, waterColor);
		DrawRectangleRec(_trampoline, _trampColor);
	}
}