#ifndef TRUCK_H
#define TRUCK_H

#include "raylib.h"

namespace SummerLab {

	class truck {
	private:
		Rectangle _body;
		Color _color;
		float _waterTank;
		float _pressure;
		Rectangle _waterShot;
	public:
		truck(float width, float height, float posX, float posY);
		~truck();
		void setBodyHeight(float height);
		void setBodyWidth(float width);
		void setBodyX(float x);
		void setBodyY(float y);
		void setWaterTank(float waterTank);
		void setPressure(float pressure);
		void setWaterShotX(float x);
		void setWaterShotY(float y);
		void setWaterShotWidth(float width);
		Rectangle getWaterShot();
		float getBodyHeight();
		float getBodyWidth();
		float getBodyX();
		float getBodyY();
		float getWaterTank();
		float getPressure();
		float getWaterShotX();
		float getWaterShotY();
		float getWaterShotWidth();
		void move();
		void shoot();
		void draw();
	};
}
#endif