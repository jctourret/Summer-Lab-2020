#ifndef CIVILIAN_H
#define CIVILIAN_H

#include "raylib.h"

namespace SummerLab {
	
	enum Direction {
		Left,
		Up,
		Right,
		None,
	};

	class Civilian{
	private:
		Rectangle _body;
		bool _isAlive;
		Color _color;
		bool _onRoof;
		float _onRoofTimer;
		bool _jumping;
		Vector2 _jumpForce;
		Direction _bounceDirection;
		Vector2 _bounceForce;
	public:
		Civilian(float height, float width, float x, float y);
		~Civilian();
		void setOnRoof(bool onRoof);
		void setJumping(bool jumping);
		void setBounceDirection(Direction x);
		bool getIsAlive();
		bool getOnRoof();
		bool getJumping();
		Rectangle getBody();
		void jump();
		void jumpTimer();
		void bounce();
		void resetBounceForce();
		void die();
		void draw();
	};

}

#endif