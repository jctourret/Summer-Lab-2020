#ifndef CIVILIAN_H
#define CIVILIAN_H

#include "raylib.h"

namespace SummerLab {
	
	enum Direction {
		cLeft,
		cUp,
		cRight,
		cNone,
	};

	class Civilian{
	private:
		Rectangle _body;
		bool _isAlive;
		bool _isSaved;
		bool _jumping;
		bool _onRoof;
		float _onRoofTimer;
		Color _color;
		Vector2 _jumpForce;
		Direction _bounceDirection;
		Vector2 _bounceForce;
		Texture2D _normalFemaleCiv1;
		Texture2D _normalFemaleCiv2;
		Texture2D _normalFemaleCiv3;
		Texture2D _normalMaleCiv1;
		Texture2D _normalMaleCiv2;
		Texture2D _normalMaleCiv3;
		Texture2D _workingFemaleCiv1;
		Texture2D _workingFemaleCiv2;
		Texture2D _workingFemaleCiv3;
		Texture2D _workingMaleCiv1;
		Texture2D _workingMaleCiv2;
		Texture2D _workingMaleCiv3;
		Texture2D _partyFemaleCiv1;
		Texture2D _partyFemaleCiv2;
		Texture2D _partyFemaleCiv3;
		Texture2D _partyMaleCiv1;
		Texture2D _partyMaleCiv2;
		Texture2D _partyMaleCiv3;
	public:
		Civilian(float height, float width, float x, float y);
		~Civilian();
		void setOnRoof(bool onRoof);
		void setJumping(bool jumping);
		void setBounceDirection(Direction x);
		bool getIsAlive();
		bool getIsSaved();
		bool getOnRoof();
		bool getJumping();
		Rectangle getBody();
		void jump();
		void jumpTimer();
		void bounce();
		void resetBounceForce();
		void die();
		void saved();
		void draw();
	};

}

#endif