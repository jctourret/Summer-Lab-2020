#include "Civilian.h"

#include "System/screen.h"

using namespace SummerLab;

namespace SummerLab {

	const Color civColor = GREEN;

	const float xJumpForce = 25;
	const float yJumpForce = 80;
	const float xBounceForce = 10;
	const float yBounceForce = 180;
	const float gravity = 60;

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
		_bounceDirection = None;
		_bounceForce.x = xBounceForce;
		_bounceForce.y = yBounceForce;
		Image normalFemaleCiv1 = LoadImage("res/assets/img/civilians/normalFemale1.png");
		ImageResize(&normalFemaleCiv1, width, height);
		_normalFemaleCiv1 = LoadTextureFromImage(normalFemaleCiv1);
		UnloadImage(normalFemaleCiv1);
		Image normalFemaleCiv2 = LoadImage("res/assets/img/civilians/normalFemale2.png");
		ImageResize(&normalFemaleCiv2, width, height);
		_normalFemaleCiv2 = LoadTextureFromImage(normalFemaleCiv2);
		UnloadImage(normalFemaleCiv2);
		Image normalFemaleCiv3 = LoadImage("res/assets/img/civilians/normalFemale3.png");
		ImageResize(&normalFemaleCiv3, width, height);
		_normalFemaleCiv3 = LoadTextureFromImage(normalFemaleCiv3);
		UnloadImage(normalFemaleCiv3);
		_normalMaleCiv1 = LoadTexture("res/assets/img/civilians/normalMale1.png");;
		_normalMaleCiv2 = LoadTexture("res/assets/img/civilians/normalMale2.png");;
		_normalMaleCiv3 = LoadTexture("res/assets/img/civilians/normalMale3.png");;
		_workingFemaleCiv1 = LoadTexture("res/assets/img/civilians/workingFemale1.png");;
		_workingFemaleCiv2 = LoadTexture("res/assets/img/civilians/workingFemale2.png");;
		_workingFemaleCiv3 = LoadTexture("res/assets/img/civilians/workingFemale3.png");;
		_workingMaleCiv1 = LoadTexture("res/assets/img/civilians/workingMale1.png");;
		_workingMaleCiv2 = LoadTexture("res/assets/img/civilians/workingMale2.png");;
		_workingMaleCiv3 = LoadTexture("res/assets/img/civilians/workingMale3.png");;
		_partyFemaleCiv1 = LoadTexture("res/assets/img/civilians/partyFemale1.png");;
		_partyFemaleCiv2 = LoadTexture("res/assets/img/civilians/partyFemale2.png");;
		_partyFemaleCiv3 = LoadTexture("res/assets/img/civilians/partyFemale3.png");;
		_partyMaleCiv1 = LoadTexture("res/assets/img/civilians/partyMale1.png");;
		_partyMaleCiv2 = LoadTexture("res/assets/img/civilians/partyMale2.png");;
		_partyMaleCiv3 = LoadTexture("res/assets/img/civilians/partyMale3.png");;
	}

	Civilian::~Civilian(){
		UnloadTexture(_normalFemaleCiv1);
		UnloadTexture(_normalFemaleCiv2);
		UnloadTexture(_normalFemaleCiv3);
		UnloadTexture(_normalMaleCiv1);
		UnloadTexture(_normalMaleCiv2);
		UnloadTexture(_normalMaleCiv3);
		UnloadTexture(_workingFemaleCiv1);
		UnloadTexture(_workingFemaleCiv2);
		UnloadTexture(_workingFemaleCiv3);
		UnloadTexture(_workingMaleCiv1);
		UnloadTexture(_workingMaleCiv2);
		UnloadTexture(_workingMaleCiv3);
		UnloadTexture(_partyFemaleCiv1);
		UnloadTexture(_partyFemaleCiv2);
		UnloadTexture(_partyFemaleCiv3);
		UnloadTexture(_partyMaleCiv1);
		UnloadTexture(_partyMaleCiv2);
		UnloadTexture(_partyMaleCiv3);
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
		if (_bounceDirection == None) {
			_body.x += _jumpForce.x * time;
			_body.y -= _jumpForce.y * time;
			_jumpForce.y -= gravity * time;
		}
	}

	void Civilian::bounce() {
		if (_isAlive  && !_isSaved) {
			float time = GetFrameTime();
			switch (_bounceDirection) {
			case Left:
				_body.x += _bounceForce.x * time;
				_body.y -= _bounceForce.y * time;
				_bounceForce.y -= gravity * time;
				break;
			case Up:
				_body.y -= _bounceForce.y * time;
				_bounceForce.y -= gravity * time;
				break;
			case Right:
				_body.x -= _bounceForce.x * time;
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
			DrawTexture(_normalFemaleCiv1, _body.x, _body.y, RAYWHITE);
		}
	}
}