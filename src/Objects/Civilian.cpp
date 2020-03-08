#include "Civilian.h"

#include "System/screen.h"
#include "Sprites/civilians_sprites.h"

using namespace SummerLab;

namespace SummerLab {

	const Color civColor = GREEN;

	const float xJumpForce = 25;
	const float yJumpForce = 80;
	const float xBounceForce = 25;
	const float yBounceForce = 180;
	const float gravity = 60;

	static const int minNumSprites = 0;
	static const int maxNumSprites = 5;

	static const int maxSpritesVariants = 3;

	Civilian::Civilian(float height, float width,float x, float y){
		_body.height = height;
		_body.width = width;
		_body.x = x;
		_body.y = y;
		_isAlive = true;
		_isSaved = false;
		_onRoof = false;
		_jumping = false;
		_color = civColor;
		_onRoofTimer = 0;
		_jumpForce.x = yJumpForce;
		_jumpForce.y = xJumpForce;
		_bounceDirection = cNone;
		_bounceForce.x = xBounceForce;
		_bounceForce.y = yBounceForce;
		_class = GetRandomValue(minNumSprites, maxNumSprites);

		for (int i = 0; i < maxSpritesVariants; i++) {
			switch (_class) {
			case NormalFemaleSprite:
				_sprites[i] = normalFemale[i];
				break;
			case NormalMaleSprite:
				_sprites[i] = normalMale[i];
				break;
			case PartyFemaleSprite:
				_sprites[i] = partyFemale[i];
				break;
			case PartyMaleSprite:
				_sprites[i] = partyMale[i];
				break;
			case WoringFemaleSprite:
				_sprites[i] = workingFemale[i];
				break;
			case WorkingMaleSprite:
				_sprites[i] = workingMale[i];
				break;
			}
		}
	}

	Civilian::~Civilian(){
		for (int i = 0; i < maxSpritesVariants; i++) {
			UnloadTexture(_sprites[i]);
		}
	}

	void Civilian::setOnRoof(bool onRoof) {
		_onRoof = onRoof;
	}

	void Civilian::setJumping(bool jumping) {
		_jumping = jumping;
	}

	void Civilian::setBounceDirection(Direction x) {
		_bounceDirection = x;
	}

	bool Civilian::getIsAlive() {
		return _isAlive;
	}

	bool Civilian::getIsSaved() {
		return _isSaved;
	}

	bool Civilian::getOnRoof() {
		return _onRoof;
	}

	bool Civilian::getJumping() {
		return _jumping;
	}

	Rectangle Civilian::getBody() {
		return _body;
	}

	void Civilian::jump() {
		float time = GetFrameTime();
		if (_bounceDirection == cNone) {
			//_body.x += _jumpForce.x * time;
			_body.y -= _jumpForce.y * time;
			_jumpForce.y -= gravity * time;
		}
	}

	void Civilian::bounce() {
		if (_isAlive  && !_isSaved) {
			float time = GetFrameTime();
			switch (_bounceDirection) {
			case cLeft:
				_body.x -= _bounceForce.x * time;
				_body.y -= _bounceForce.y * time;
				_bounceForce.y -= gravity * time;
				break;
			case cUp:
				_body.y -= _bounceForce.y * time;
				_bounceForce.y -= gravity * time;
				break;
			case cRight:
				_body.x += _bounceForce.x * time;
				_body.y -= _bounceForce.y * time;
				_bounceForce.y -= gravity * time;
				break;
			}
		}
	}

	void Civilian::resetBounceForce() {
		_bounceForce.y = yBounceForce;
	}
	 
	void Civilian::jumpTimer() {
		_onRoofTimer += GetFrameTime();
		if (_onRoofTimer >= 5.0f) {
			_jumping = true;
			_onRoofTimer = 0.0f;
		}
		if (_jumping) {
			jump();
		}
	}

	void Civilian::die() {
		if (_body.y+_body.height >= screenHeight - screenHeight/20 && _isAlive) {
			_isAlive = false;
		}
	}

	void Civilian::saved() {
		_isSaved = true;
	}

	void Civilian::draw() {
		if ((getOnRoof() || getJumping()) && _isAlive && !_isSaved) {
			DrawRectangleRec(_body, _color);
			DrawTexture(_sprites[0], _body.x, _body.y, RAYWHITE);
		}
	}
}