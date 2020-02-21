#include "cannon.h"

using namespace SummerLab;

namespace SummerLab {

	const Color waterColor = SKYBLUE;

	const float maxWaterTank = 100;
	const float waterShotWidth = 10;

	const float pressureChargeRate = 200;
	const float pressureDischargeRate = 180;

	cannon::cannon(float x, float y) {
		_waterTank = maxWaterTank;
		_pressure = 0;
		_waterShot.height = 0;
		_waterShot.width = waterShotWidth;
		_waterShot.x = x;
		_waterShot.y = y;
	}

	cannon::~cannon() {

	}

	void cannon::setWaterTank(float waterTank) {
		_waterTank = waterTank;
	}
	void cannon::setPressure(float pressure) {
		_pressure = pressure;
	}
	void cannon::setWaterShotX(float x) {
		_waterShot.x = x;
	}
	void cannon::setWaterShotY(float y) {
		_waterShot.y = y;
	}
	void cannon::setWaterShotWidth(float width) {
		_waterShot.width = width;
	}

	
	float cannon::getWaterTank() {
		return _waterTank;
	}
	float cannon::getPressure() {
		return _pressure;
	}
	float cannon::getWaterShotX() {
		return _waterShot.x;
	}
	float cannon::getWaterShotY() {
		return _waterShot.y;
	}
	float cannon::getWaterShotWidth() {
		return _waterShot.width;
	}

	void cannon::shoot() {
		float time = GetFrameTime();
		if (IsKeyDown(KEY_UP)) {
			_pressure += pressureChargeRate * time;
			_waterShot.y -= pressureChargeRate * time;
		}
		if (_pressure > 0 && IsKeyUp(KEY_UP)) {
			_pressure -= pressureDischargeRate * time;
			_waterShot.y += pressureDischargeRate * time;
		}
		_waterShot.height = _pressure;
	}

	void cannon::draw() {
		DrawRectangleRec(_waterShot, waterColor);
	}

}