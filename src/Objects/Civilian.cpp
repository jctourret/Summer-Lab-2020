#include "Civilian.h"

using namespace SummerLab;

namespace SummerLab {

	Civilian::Civilian(float height, float width,float x, float y){
		_body.height = height;
		_body.width = width;
		_body.x = x;
		_body.y = y;
	}

	Civilian::~Civilian(){

	}
}