#include "truck.h"

using namespace SummerLab;

namespace SummerLab {
	
	const float truckSpeed = 500;

	const float truckHeight = 100;
	const float truckWidth = 200;

	truck::truck(float height, float width, float posX, float posY){
		_body.height = height;
		_body.width = width;
		_body.x = posX;
		_body.y = posY;
	}

	truck::~truck(){

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
	void truck::move() {
		float time = GetFrameTime();
		if (IsKeyDown(KEY_LEFT)) {
			_body.y -= truckSpeed*time;
		}
		if (IsKeyDown(KEY_RIGHT)) {
			_body.y += truckSpeed * time;
		}
	}
}