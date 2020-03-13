#include "Ambulance.h"

#include "System/screen.h"
#include "Sprites/ambulance_sprites.h"

using namespace SummerLab;

namespace SummerLab {

	static const float ambulanceSpeed = 500;

	const Color ambulanceColor = RAYWHITE;

	Ambulance::Ambulance(float height, float width,float x, float y) {
		_body.height = height;
		_body.width = width;
		_body.x = x;
		_body.y = y;
		_color = ambulanceColor;
		_ambulanceRight = ambulanceRightSprite;
		_ambulanceLeft = ambulanceLeftSprite;
		_waitingCiv = false;
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
		if (_body.x < screenWidth / 2 && _waitingCiv) {
			_body.x -= ambulanceSpeed * time;
			if (_body.x < -_body.width) {
				_waitingCiv = false;
			}
		}
		if (_body.x < screenWidth / 2 && !_waitingCiv) {
			if (_body.x < screenWidth / 15) {
				_body.x += ambulanceSpeed * time;
				_waitingCiv = true;
			}
		}
		if (_body.x > screenWidth / 2 && _waitingCiv) {
			_body.x += ambulanceSpeed * time;
			if (_body.x > screenWidth + _body.width) {
				_waitingCiv = false;
			}
		}
		if (_body.x < screenWidth / 2 && !_waitingCiv) {
			if (_body.x < screenWidth - screenWidth / 15 - 342) {
				_body.x += ambulanceSpeed * time;
				_waitingCiv = true;
			}
		}
	}

	void Ambulance::draw() {
		if (_body.x > screenWidth / 2) {
			DrawTexture(_ambulanceRight, _body.x, _body.y, RAYWHITE);
		}
		if (_body.x < screenWidth / 2) {
			DrawTexture(_ambulanceLeft, _body.x, _body.y, RAYWHITE);
		}
	}
}