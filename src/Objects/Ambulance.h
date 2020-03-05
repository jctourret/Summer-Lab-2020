#ifndef AMBULANCE_H
#define AMBULANCE_H

#include "raylib.h"

namespace SummerLab {
	
	enum Facing {
		Left,
		Right,
	};

	class Ambulance {
	private:
		Rectangle _body;
		Color _color;
		Facing _facing;
	public:
		Ambulance(float height, float width, float x, float y, Facing side);
		~Ambulance();
		void draw();
	};
}
#endif