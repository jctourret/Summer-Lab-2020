#ifndef CIVILIAN_H
#define CIVILIAN_H

#include "raylib.h"

namespace SummerLab {
	
	class Civilian{
	private:
		Rectangle _body;
		Color _color;
		bool _onRoof;
		float _onRoofTimer;
		bool _jumping;
	public:
		Civilian(float height, float width, float x, float y);
		~Civilian();
		void setOnRoof(bool onRoof);
		void setJumping(bool jumping);
		bool getOnRoof();
		bool getJumping();
		void spawn();
		void jump();
		void jumpTimer();
		void draw();
	};

}

#endif