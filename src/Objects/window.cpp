#include "window.h"


namespace SummerLab {
	
	const Color windowColor = BLUE;

	window::window(float height, float width, float x, float y){
		_body.height = height;
		_body.width = width;
		_body.x = x;
		_body.y = y;
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

	void window::draw() {
		DrawRectangleRec(_body, _color);
	}
}