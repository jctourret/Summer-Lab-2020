#include "building.h"

#include "cannon.h"

using namespace SummerLab;

namespace SummerLab {

	const Color buildingColor = GRAY;
	const float windowOffset = 60;
	const float windowHeight = 90;
	const float windowWidth = 90;

	building::building(float height, float width, float x, float y, int floors, int columns) {
		_body.height = height;
		_body.width = width;
		_body.x = x;
		_body.y = y;
		_floors = floors;
		_columns = columns;
		for (int k = 0; k < (columns + floors); k) {
			for (int i = 0; i < columns; i++) {
				for (int j = 0; j < floors; j++) {
					_windows[k] = new window(windowHeight, windowWidth, (_body.x + windowOffset + (j*(_body.width / _columns))), (_body.y + windowOffset) + (i*(_body.height / (_floors+1))));
					k++;
				}
			}
		}
		_color = buildingColor;
	}

	building::~building() {

	}
	
	void building::initFire() {
		for  (int i = 0; i < _columns; i++){
			_windows[i]->catchFire();
		}
	}

	void building::growFireTimers() {
		for (int i = 0; i < (_columns*_floors); i++){
			_windows[i]->dozeFireTimer();
		}
	}
	
	void building::dozeFireTimers(cannon* cannon){
		for (int i = 0; i < (_columns*_floors); i++) {
			if (cannon->getWaterShotX() >= _windows[i]->getWindowX() - (cannon->getWaterShotWidth()) &&
				cannon->getWaterShotX() <= _windows[i]->getWindowX()+ _windows[i]->getWindowWidth() &&
				cannon->getWaterShotY() < _windows[i]->getWindowY() &&
				cannon->getWaterShotY() > _windows[i]->getWindowY() + _windows[i]->getWindowHeight())
			_windows[i]->dozeFireTimer();
		}
	}

	void building::draw() {
		DrawRectangleRec(_body, _color);
		for (int i = 0; i < (_floors*_columns); i++){
			_windows[i]->draw();
		}
	}
}