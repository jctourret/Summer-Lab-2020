#include "Ambulance.h"

#include "System/screen.h"

using namespace SummerLab;

namespace SummerLab {

	const Color ambulanceColor = RAYWHITE;

	Ambulance::Ambulance(float height, float width,float x, float y) {
		_body.height = height;
		_body.width = width;
		_body.x = x;
		_body.y = y;
		_color = ambulanceColor;
		Image ambulanceLeft = LoadImage("res/assets/img/ambulance/ambulanceLeft.png");
		ImageResize(&ambulanceLeft, _body.width, _body.height);
		_ambulanceLeft = LoadTextureFromImage(ambulanceLeft);
		UnloadImage(ambulanceLeft);
		Image ambulanceRight = LoadImage("res/assets/img/ambulance/ambulanceRight.png");
		ImageResize(&ambulanceRight, _body.width, _body.height);
		_ambulanceRight = LoadTextureFromImage(ambulanceRight);
		UnloadImage(ambulanceRight);
	}

	Ambulance::~Ambulance(){
	}

	Rectangle Ambulance::getBody() {
		return _body;
	}

	void Ambulance::draw() {
		DrawRectangleRec(_body, _color);
		if (_body.x > screenWidth / 2) {
			DrawTexture(_ambulanceRight, _body.x, _body.y, RAYWHITE);
		}
		if (_body.x < screenWidth / 2) {
			DrawTexture(_ambulanceLeft, _body.x, _body.y, RAYWHITE);
		}
	}
}