#ifndef TRUCK_H
#define TRUCK_H

#include "raylib.h"

namespace SummerLab {

	enum BounceDirection {
		bLeft,
		bUp,
		bRight,
		bNone,
	};

	class truck {
	private:
		Rectangle _body;
		Color _color;
		float _waterTank;
		float _pressure;
		Rectangle _waterShotLine;
		Rectangle _trampoline;
		Color _trampColor;
		Texture2D _truckSprites[5];
		Texture2D _sirenSprite;
		Texture2D _menuTruckSprites[5];
		Texture2D _menuSirenSprite;
		Texture2D _waterShot1[3];
		Texture2D _waterShot2[3];
		Texture2D _waterShot3[3];
		Texture2D _waterShot4[3];
		Texture2D _waterShot5[3];
		Texture2D _waterShot6[3];
		Texture2D _waterShot7[3];
		float _timerSiren;
		Sound _truckSiren;
		Sound _motorOn;
		Sound _motorOff;
		Sound _motorLoop;
		Sound _waterShot;
		float _timerFrame;
		int _numFrame;
		bool _bounceOnce;
		bool _isOnMenu;
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
		void setIsOnMenu(bool isOnMenu);
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
		void move(bool keyboard, bool hose);
		void shoot(bool keyboard, bool hose);
		void recharge(Rectangle rec, bool keyboard, bool hose);
		BounceDirection checkBounce(Rectangle rec);
		void draw();
	};
}
#endif