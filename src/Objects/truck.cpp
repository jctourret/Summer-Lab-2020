#include "truck.h"

using namespace SummerLab;

namespace SummerLab {

	const Color waterColor = SKYBLUE;

	const float maxWaterTank = 100;
	const float waterShotWidth = 10;

	const float pressureChargeRate = 200;
	const float pressureDischargeRate = 180;
	const float tankDrainRate = 5;
	const float tankRechargeRate = 100;

	const float truckSpeed = 500;

	const float truckHeight = 100;
	const float truckWidth = 200;
	const Color truckColor = RED;

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
		}
		if (IsKeyDown(KEY_RIGHT)) {
			_body.x += truckSpeed * time;
			_waterShot.x += (truckSpeed * time);
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
			(_pressure > 0 && _waterTank <=0)) {
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

	void truck::draw() {
		DrawRectangleRec(_body,_color);
		DrawRectangleRec(_waterShot, waterColor);
	}
}