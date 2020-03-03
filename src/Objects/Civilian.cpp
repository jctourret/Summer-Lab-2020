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
		_color = civColor;
		_onRoof = false;
		_jumping = false;
		_onRoofTimer = 0;
		_jumpForce.x = yJumpForce;
		_jumpForce.y = xJumpForce;
		_bounceDirection = None;
		_bounceForce.x = xBounceForce;
		_bounceForce.y = yBounceForce;
	}

	Civilian::~Civilian(){

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
		if (_isAlive) {
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
		if (_body.y+_body.height >= screenHeight - screenHeight/20) {
			_isAlive = false;
		}
	}

	void Civilian::draw() {
		if ((getOnRoof() || getJumping()) && _isAlive) {
			DrawRectangleRec(_body, _color);
		}
	}
}