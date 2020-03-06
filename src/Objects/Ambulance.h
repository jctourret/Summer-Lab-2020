#ifndef AMBULANCE_H
#define AMBULANCE_H

#include "raylib.h"

namespace SummerLab {

	class Ambulance {
	private:
		Rectangle _body;
		Color _color;
		Texture2D _ambulanceLeft;
		Texture2D _ambulanceRight;
	public:
		Ambulance(float height, float width, float x, float y);
		~Ambulance();
		Rectangle getBody();
		void draw();
	};
}
#endif