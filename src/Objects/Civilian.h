#ifndef CIVILIAN_H
#define CIVILIAN_H

#include "raylib.h"

namespace SummerLab {
	
	class Civilian{
	private:
		Rectangle _body;
	public:
		Civilian(float height, float width, float x, float y);
		~Civilian();
	};

}

#endif