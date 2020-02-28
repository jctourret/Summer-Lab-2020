#include "building.h"

using namespace SummerLab;

namespace SummerLab {

	const Color buildingColor = GRAY;
	const float windowOffset = 60;
	const float windowHeight = 90;
	const float windowWidth = 90;
	const float civOffset = 90;
	const float civHeight = 90;
	const float civWidth = 90;

	float civSpawnTimer = 0.0f;

	bool firstFire = true;

	building::building(float height, float width, float x, float y, int floors, int columns) {
		_body.height = height;
		_body.width = width;
		_body.x = x;
		_body.y = y;
		_floors = floors;
		_columns = columns;
		for (int k = 0; k < (columns + floors); k) {
			for (int i = 0; i < floors; i++) {
				for (int j = 0; j < columns; j++) {
					_windows[k] = new window(windowHeight, windowWidth, (_body.x + windowOffset + (j*(_body.width / _columns))), (_body.y + windowOffset) + (i*(_body.height / (_floors+1))));
					k++;
				}
			}
		}
		for (int k = 0; k < (columns * floors); k) {
			for (int j = 0; j < floors; j++) {
				_civilians[k] = new Civilian(civHeight, civWidth, (_body.x + civOffset + (j*(_body.width / _columns))), (_body.y + civHeight));
				k++;
			}
		}
		_color = buildingColor;
	}

	building::~building() {

	}
	
	void building::initFire() {
		if (firstFire) {
			for (int i = 0; i < _columns; i++) {
				_windows[i]->catchFire();
			}
			firstFire = false;
		}
	}

	void building::growFireTimers() {
		for (int i = 0; i < (_columns*_floors); i++){
			if (_windows[i]->getOnFire()){
				_windows[i]->growFireTimer();
			}
		}
	}
	
	void building::dozeFireTimers(Rectangle rec){
		for (int i = 0; i < (_columns*_floors); i++) {
			if (_windows[i]->getOnFire()) {
				if (rec.x >= _windows[i]->getWindowX() - (rec.width) &&
					rec.x <= _windows[i]->getWindowX() + _windows[i]->getWindowWidth() + rec.width &&
					rec.y > _windows[i]->getWindowY() &&
					rec.y < _windows[i]->getWindowY() + _windows[i]->getWindowHeight()) {
					_windows[i]->dozeFireTimer();
				}
			}
		}
	}

	void building::spreadFireTimers() {
		for (int i = 0; i < _columns; i++) {
			if (_windows[i + _columns]->getOnFire() && !_windows[i]->getOnFire()) {
				_windows[i]->spreadFireTimer();
			}
		}
		for (int i = 0; i < _floors; i++){
			if (_windows[(i*_columns) + 1]->getOnFire() && !_windows[i]->getOnFire()) {
				_windows[i*_columns]->spreadFireTimer();
			}
		}
		for  (int i = _columns; i < (_columns*_floors)-_columns; i++){
			if (_windows[i - _columns]->getOnFire() && !_windows[i]->getOnFire()||
				_windows[i + _columns]->getOnFire() && !_windows[i]->getOnFire()) {
				_windows[i]->spreadFireTimer();
			}
		}
		for (int i = _columns + 1; i < (_columns*_floors) - 1; i) {
			if (_windows[i - 1]->getOnFire() && !_windows[i]->getOnFire() ||
				_windows[i + 1]->getOnFire() && !_windows[i]->getOnFire()) {
				_windows[i]->spreadFireTimer();
			}
			i++;
			if (i == _columns - 1) {
				i += 2;
			}
		}
		for (int i = _columns-1; i < (_columns-1)*_floors; i+=_columns) {
			if (_windows[i - 1]->getOnFire() && !_windows[i]->getOnFire()) {
				_windows[i]->spreadFireTimer();
			}
		}
		for (int i = (_columns*_floors) - _columns; i < (_columns*_floors); i++) {
			if (_windows[i - _columns]->getOnFire() && !_windows[i]->getOnFire()) {
				_windows[i]->spreadFireTimer();
			}
		}
	}

	void building::spawnCiv() {
		civSpawnTimer += GetFrameTime();
		if (civSpawnTimer >= 5.0f) {
			int random = GetRandomValue(0, (_columns*_floors) - 1);
			_civilians[random]->setOnRoof(true);
			civSpawnTimer = 0.0f;
		}
	}

	void building::civJumpTimers() {
		for (int i = 0; i < _columns*_floors; i++){
			if (_civilians[i]->getOnRoof()){
				
			}
		}
	}

	void building::draw() {
		DrawRectangleRec(_body, _color);
		for (int i = 0; i < (_floors*_columns); i++){
			_windows[i]->draw();
		}
		for (int i = 0; i < (_floors*_columns); i++) {
			_civilians[i]->draw();
		}
	}
}