#include "Ambulance.h"

using namespace SummerLab;

namespace SummerLab {

	const Color ambulanceColor = RAYWHITE;

	Ambulance::Ambulance(float height, float width,float x, float y, Facing side) {
		_body.height = height;
		_body.width = width;
		_body.x = x;
		_body.y = y;
		_color = ambulanceColor;
		_facing = side;
	}

	Ambulance::~Ambulance(){
	}

	void Ambulance::draw() {
		DrawRectangleRec(_body, _color);
	}
}