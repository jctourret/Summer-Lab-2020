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

	enum Sprite {
		NormalFemaleSprite,
		NormalMaleSprite,
		PartyFemaleSprite,
		PartyMaleSprite,
		WoringFemaleSprite,
		WorkingMaleSprite
	};

	class Civilian{
	private:
		Rectangle _body;
		bool _isAlive;
		bool _isSaved;
		bool _jumping;
		bool _onRoof;
		float _onRoofTimer;
		float _animTimer;
		Color _color;
		Vector2 _jumpForce;
		Direction _bounceDirection;
		Vector2 _bounceForce;
		Texture2D _sprites[3];
		Sound _helpScream;
		int _class;
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
		void animTimer();
		void bounce();
		void resetBounceForce();
		void die();
		void saved();
		void draw();
	};

}

#endif