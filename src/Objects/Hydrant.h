#ifndef HYDRANT_H
#define HYDRANT_H

#include "raylib.h"

namespace SummerLab {

	class Hydrant {
	private:
		Rectangle _body;
		Color _color;
	public:
		Hydrant(float x, float y);
		~Hydrant();
		Rectangle getBody();
	};
}

#endif 