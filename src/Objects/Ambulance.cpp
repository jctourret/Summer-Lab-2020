#include "Ambulance.h"

using namespace SummerLab;

namespace SummerLab {

	const Color ambulanceColor = RAYWHITE;

	Ambulance::Ambulance(float height, float width,float x, float y) {
		_body.height = height;
		_body.width = width;
		_body.x = x;
		_body.y = y;
		_color = ambulanceColor;
	}

	Ambulance::~Ambulance(){
	}

	Rectangle Ambulance::getBody() {
		return _body;
	}

	void Ambulance::draw() {
		DrawRectangleRec(_body, _color);
	}
}