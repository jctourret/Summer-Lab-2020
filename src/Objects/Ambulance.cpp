#include "Ambulance.h"

#include "System/screen.h"
#include "Sprites/ambulance_sprites.h"

using namespace SummerLab;

namespace SummerLab {

	const Color ambulanceColor = RAYWHITE;

	Ambulance::Ambulance(float height, float width,float x, float y) {
		_body.height = height;
		_body.width = width;
		_body.x = x;
		_body.y = y;
		_color = ambulanceColor;
		_ambulanceRight = ambulanceRightSprite;
		_ambulanceLeft = ambulanceLeftSprite;
	}

	Ambulance::~Ambulance(){
		UnloadTexture(_ambulanceRight);
		UnloadTexture(_ambulanceLeft);
	}

	Rectangle Ambulance::getBody() {
		return _body;
	}

	void Ambulance::draw() {
		if (_body.x > screenWidth / 2) {
			DrawTexture(_ambulanceRight, _body.x, _body.y, RAYWHITE);
		}
		if (_body.x < screenWidth / 2) {
			DrawTexture(_ambulanceLeft, _body.x, _body.y, RAYWHITE);
		}
	}
}