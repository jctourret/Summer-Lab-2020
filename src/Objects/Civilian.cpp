#include "Civilian.h"

#include "System/screen.h"
#include "Sprites/civilians_sprites.h"
#include "Music/civilians_sfx.h"

using namespace SummerLab;

namespace SummerLab {

	const Color civColor = GREEN;

	const float xJumpForce = 25;
	const float yJumpForce = 80;
	const float xBounceForce = 30;
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
		_animTimer = 0;
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
				_helpScream = helpFemale;
				break;
			case NormalMaleSprite:
				_sprites[i] = normalMale[i];
				_helpScream = helpMale;
				break;
			case PartyFemaleSprite:
				_sprites[i] = partyFemale[i];
				_helpScream = helpFemale;
				break;
			case PartyMaleSprite:
				_sprites[i] = partyMale[i];
				_helpScream = helpMale;
				break;
			case WoringFemaleSprite:
				_sprites[i] = workingFemale[i];
				_helpScream = helpFemale;
				break;
			case WorkingMaleSprite:
				_sprites[i] = workingMale[i];
				_helpScream = helpMale;
				break;
			}
		}
	}

	Civilian::~Civilian(){
		/*for (int i = 0; i < maxSpritesVariants; i++) {
			UnloadTexture(_sprites[i]);
		}*/
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
			_body.y -= _jumpForce.y * time * 2;
			_jumpForce.y -= gravity * time * 2;
		}
		if (_jumpForce.y < 0) {
			_body.width = 121.5f;
			_body.height = 92.0f;
		}
	}

	void Civilian::bounce() {
		if (_isAlive  && !_isSaved) {
			float time = GetFrameTime();
			switch (_bounceDirection) {
			case cLeft:
				_body.x -= _bounceForce.x * time * 3;
				_body.y -= _bounceForce.y * time * 2;
				_bounceForce.y -= gravity * time * 2;
				break;
			case cUp:
				_body.y -= _bounceForce.y * time * 2;
				_bounceForce.y -= gravity * time * 2;
				break;
			case cRight:
				_body.x += _bounceForce.x * time *3;
				_body.y -= _bounceForce.y * time *2;
				_bounceForce.y -= gravity * time *2;
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
		animTimer();
		if ((getOnRoof() || getJumping()) && _isAlive && !_isSaved) {
			if (_body.width < 100){
				if (_animTimer <= 0.5f) {
					DrawTexture(_sprites[0], _body.x, _body.y, RAYWHITE);
				}
				if (_animTimer > 0.5f && _animTimer <= 1.0f) {
					DrawTexture(_sprites[1], _body.x, _body.y, RAYWHITE);
					if (IsSoundPlaying(_helpScream)){
					PlaySound(_helpScream);
				}
				}
				if (_animTimer>1.0f) {
					_animTimer = 0.0f;
				}
			}
			else {
				DrawTexture(_sprites[2], _body.x, _body.y, RAYWHITE);
			}
		}
	}

	void Civilian::animTimer() {
		_animTimer += GetFrameTime();
	}
}