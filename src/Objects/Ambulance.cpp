#include "Ambulance.h"

#include "System/screen.h"
#include "Sprites/ambulance_sprites.h"

using namespace SummerLab;

namespace SummerLab {

	static const float ambulanceSpeed = 500;

	const Color ambulanceColor = RAYWHITE;

	Ambulance::Ambulance(float height, float width,float x, float y, bool positionRight, bool positionLeft) {
		_body.height = height;
		_body.width = width;
		_body.x = x;
		_posXInitial = x;
		_body.y = y;
		_color = ambulanceColor;
		_ambulanceRight = ambulanceRightSprite;
		_ambulanceLeft = ambulanceLeftSprite;
		_waitingCiv = true;
		_posRight = positionRight;
		_posLeft = positionLeft;
	}

	Ambulance::~Ambulance(){
		UnloadTexture(_ambulanceRight);
		UnloadTexture(_ambulanceLeft);
	}

	void Ambulance::setWaitingCiv(bool waitingCiv) {
		_waitingCiv = waitingCiv;
	}

	Rectangle Ambulance::getBody() {
		return _body;
	}

	void Ambulance::takeCivAway() {
		float time = GetFrameTime();
		if (_posLeft == true) {
			if (_waitingCiv == false) {
				_body.x -= ambulanceSpeed * time;
				if (_body.x < -_body.width) {
					_waitingCiv = true;
				}
			}
			else if ( _waitingCiv == true) {
				if (_body.x < _posXInitial) {
					_body.x += ambulanceSpeed * time;
				}
			}
		}
		else if (_posRight == true) {
			if (_waitingCiv == false) {
				_body.x += ambulanceSpeed * time;
				if (_body.x > screenWidth + _body.width) {
					_waitingCiv = true;
				}
			}
			else if (_waitingCiv == true) {
				if (_body.x > _posXInitial) {
					_body.x -= ambulanceSpeed * time;
				}
			}
		}
	}

	void Ambulance::draw() {
		if(_posRight == true) {
			DrawTexture(_ambulanceRight, _body.x, _body.y, RAYWHITE);
		}
		else if (_posLeft == true) {
			DrawTexture(_ambulanceLeft, _body.x, _body.y, RAYWHITE);
		}
	}
}