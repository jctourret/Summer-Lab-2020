#include "Hydrant.h"


using namespace SummerLab;

namespace SummerLab {

	static float hydrantHeight = 100;
	static float hydrantWidth = 50;
	static Color hydrantColor = MAROON;

	Hydrant::Hydrant(float x, float y) {
		_body.height = hydrantHeight;
		_body.width = hydrantWidth;
		_body.x = x;
		_body.y = y;
		_color = hydrantColor;
	}

	Hydrant::~Hydrant(){
	}

	Rectangle Hydrant::getBody() {
		return _body;
	}
}