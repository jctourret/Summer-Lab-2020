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
		Rectangle _trampoline;
		Color _trampColor;
		Texture2D _truck100;
		Texture2D _waterShot1a;
		Texture2D _waterShot2a;
		Texture2D _waterShot3a;
		Texture2D _waterShot4a;
		Texture2D _waterShot5a;
		Texture2D _waterShot6a;
		Texture2D _waterShot7a;
		bool _bounceOnce;
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
		void recharge(Rectangle rec);
		bool checkLeftBounce(Rectangle rec);
		bool checkUpBounce(Rectangle rec);
		bool checkRightBounce(Rectangle rec);
		void draw();
	};
}
#endif