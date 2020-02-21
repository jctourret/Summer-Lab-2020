#include "window.h"


namespace SummerLab {
	
	const Color windowColor = BLUE;
	const Color smallFireColor = BLUE;
	const Color mediumFireColor = BLUE;
	const Color largeFireColor = BLUE;

	static float growTimer = 0.0f;
	static float dozeTimer = 0.0f;

	const float fireOffset = 10;

	window::window(float height, float width, float x, float y){
		_body.height = height;
		_body.width = width;
		_body.x = x;
		_body.y = y;
		_fireBody.height = height + fireOffset;
		_fireBody.width = width + fireOffset;
		_fireBody.x = x - (fireOffset/2);
		_fireBody.y = y - (fireOffset/2);
		_onFire = false;
		_fire = noFire;
		_color = windowColor;
	}

	window::~window(){
	
	}

	void window::catchFire() {
		_onFire = true;
		_fire = smallFire;
	}

	void window::dozeFire() {
		if (_fire == largeFire) {
			_fire = mediumFire;
		}
		if (_fire == mediumFire) {
			_fire = smallFire;
		}
		if (_fire == smallFire) {
			_onFire = false;
			_fire = noFire;
		}
	}

	void window::growFire() {
		if (_fire == smallFire){
			_fire = mediumFire;
		}
		if (_fire ==mediumFire){
			_fire = largeFire;
		}
	}

	void window::growFireTimer() {
		growTimer += GetFrameTime();
		if (growTimer >= 5.0f) {
			growFire();
			growTimer = 0.0f;
		}
	}
	void window::dozeFireTimer() {
		dozeTimer += GetFrameTime();
		if (dozeTimer >= 4.0f) {
			dozeFire();
			dozeTimer = 0.0f;
		}
	}

	void window::draw() {
		if (_fire == smallFire) {
			DrawRectangleRec(_fireBody, smallFireColor);
		}
		if (_fire == mediumFire) {
			DrawRectangleRec(_fireBody, mediumFireColor);
		}
		if (_fire == largeFire) {
			DrawRectangleRec(_fireBody, largeFireColor);
		}
		DrawRectangleRec(_body, _color);
	}
}