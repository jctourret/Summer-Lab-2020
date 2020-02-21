#ifndef CANNON_H
#define CANNON_H

#include "raylib.h"

namespace SummerLab {
	class cannon {
	private:
		float _waterTank;
		float _pressure;
		Rectangle _waterShot;
	public:
		cannon(float x, float y);
		~cannon();
		void setWaterTank(float waterTank);
		void setPressure(float pressure);
		void setWaterShotX(float x);
		float getWaterTank();
		float getPressure();
		float getWaterShotX();
		void shoot();
		void draw();
	};
}
#endif
