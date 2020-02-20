#ifndef TRUCK_H
#define TRUCK_H

#include "raylib.h"

namespace SummerLab {

	class truck {
	private:
		Rectangle _body;
		Color _color;
	public:
		truck(float width, float height, float posX, float posY);
		~truck();
		void setBodyHeight(float height);
		void setBodyWidth(float width);
		void setBodyX(float x);
		void setBodyY(float y);
		float getBodyHeight();
		float getBodyWidth();
		float getBodyX();
		float getBodyY();
		void move();
		void draw();
	};
}
#endif