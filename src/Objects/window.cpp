#include "window.h"

#include "Sprites/fire_sprites.h"

namespace SummerLab {
	
	const Color windowColor = BLUE;
	const Color smallFireColor = YELLOW;
	const Color mediumFireColor = ORANGE;
	const Color largeFireColor = RED;

	const float largeFireXOffset = 15;
	const float largeFireYOffset = 77;

	const float fireOffset = 10;
	static const int fireMaxSprites = 3;

	window::window(float height, float width, float x, float y){
		_body.height = height;
		_body.width = width;
		_body.x = x;
		_body.y = y;
		_fireBody.height = height + fireOffset;
		_fireBody.width = width + fireOffset;
		_fireBody.x = x - (fireOffset/2);
		_fireBody.y = y - (fireOffset/2);
		_onFire = false;
		_fire = noFire;
		_color = windowColor;
		_growTimer = 0.0f;
		_dozeTimer = 0.0f;
		_spreadTimer = 0.0f;

		for (int i = 0; i < fireMaxSprites; i++) {
			_smallFire[i] = smallFireSprite[i];
			_mediumFire[i] = mediumFireSprite[i];
			_largeFire[i] = largeFireSprite[i];
		}

	}

	window::~window(){
		for (int i = 0; i < fireMaxSprites; i++) {
			UnloadTexture(_smallFire[i]);
			UnloadTexture(_mediumFire[i]);
			UnloadTexture(_largeFire[i]);
		}
	}

	float window::getWindowWidth() {
		return _body.width;
	}
	float window::getWindowHeight() {
		return _body.height;
	}
	float window::getWindowX() {
		return _body.x;
	}
	float window::getWindowY() {
		return _body.y;
	}

	bool window::getOnFire() {
		return _onFire;
	}

	fire window::getFire() {
		return _fire;
	}

	void window::catchFire() {
		_onFire = true;
		_fire = smallFire;
	}

	void window::dozeFire() {
		if (_fire == smallFire) {
			_onFire = false;
			_fire = noFire;
		}
		if (_fire == mediumFire) {
			_fire = smallFire;
		}
		if (_fire == largeFire) {
			_fire = mediumFire;
		}
	}

	void window::growFire() {
		if (_fire == mediumFire) {
			_fire = largeFire;
		}
		if (_fire == smallFire){
			_fire = mediumFire;
		}
	}

	void window::growFireTimer() {
		_growTimer += GetFrameTime();
		if (_growTimer >= 10.0f) {
			growFire();
			_growTimer = 0.0f;
			_spreadTimer = 0.0f;
		}
	}

	void window::dozeFireTimer() {
		_dozeTimer += GetFrameTime();
		if (_dozeTimer >= 2.0f) {
			dozeFire();
			_dozeTimer = 0.0f;
			_growTimer = 0.0f;
			_spreadTimer = 0.0f;
		}
	}

	void window::spreadFireTimer() {
		_spreadTimer += GetFrameTime();
		if (_spreadTimer >= 10.0f) {
			catchFire();
			_spreadTimer = 0.0f;
			_growTimer = 0.0f;
		}
	}

	void window::draw() {
		//DrawRectangleRec(_body, _color);
		if (_fire == smallFire) {
			//DrawRectangleRec(_fireBody, smallFireColor);
			DrawTexture(_smallFire[0], _body.x, _body.y, RAYWHITE);
		}
		if (_fire == mediumFire) {
			//DrawRectangleRec(_fireBody, mediumFireColor);
			DrawTexture(_mediumFire[0], _body.x, _body.y, RAYWHITE);
		}
		if (_fire == largeFire) {
			//DrawRectangleRec(_fireBody, largeFireColor);
			DrawTexture(_largeFire[0], _body.x - largeFireXOffset, _body.y - largeFireYOffset, RAYWHITE);
		}
	}
}