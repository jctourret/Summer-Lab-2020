#include "Civilian.h"

using namespace SummerLab;

namespace SummerLab {

	const Color civColor = GREEN;

	Civilian::Civilian(float height, float width,float x, float y){
		_body.height = height;
		_body.width = width;
		_body.x = x;
		_body.y = y;
		_color = civColor;
		_onRoof = false;
		_jumping = false;
		_onRoofTimer = 0;
	}

	Civilian::~Civilian(){

	}

	void Civilian::setOnRoof(bool onRoof) {
		_onRoof = onRoof;
	}

	void Civilian::setJumping(bool jumping) {
		_jumping = jumping;
	}

	bool Civilian::getOnRoof() {
		return _onRoof;
	}

	bool Civilian::getJumping() {
		return _jumping;
	}

	void Civilian::jump() {
		
	}

	void Civilian::jumpTimer() {
		_onRoofTimer += GetFrameTime();
		if (_onRoofTimer >= 2.0f) {
			_jumping = true;
			_onRoofTimer = 0.0f;
		}
	}
	void Civilian::draw() {
		if (_onRoof || _jumping) {
			DrawRectangleRec(_body, _color);
		}
	}
}