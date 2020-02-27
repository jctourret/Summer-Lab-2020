#ifndef HYDRANT_H
#define HYDRANY_H

#include "raylib.h"

namespace SummerLab {

	class Hydrant {
	private:
		Rectangle _body;
	public:
		Hydrant();
		~Hydrant();
		draw();
	};
}

#endif 