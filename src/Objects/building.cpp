#include "building.h"

using namespace SummerLab;

namespace SummerLab {

	const Color buildingColor = GRAY;
	const float windowOffset = 50;
	const float windowHeight = 100;
	const float windowWidth = 100;

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
	
	void building::draw() {
		DrawRectangleRec(_body, _color);
		for (int i = 0; i < (_floors*_columns); i++){
			_windows[i]->draw();
		}
	}
}