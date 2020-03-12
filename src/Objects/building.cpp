#include "building.h"

#include "Music/fire_sfx.h"

using namespace SummerLab;

namespace SummerLab {

	const Color buildingColor = GRAY;
	const float windowXOffset = 75;
	const float windowYOffset = 85;
	const float lowerWindowsYOffset = 34;
	const float windowHeight = 70;
	const float windowWidth = 70;
	const float civOffset = 85;
	const float civHeight = 106;
	const float civWidth = 91;

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
					_windows[k] = new window(windowHeight, windowWidth, _body.x + windowXOffset + (j*(_body.width / _columns)) - (j*18), _body.y + windowYOffset + (i*(_body.height / (_floors+1))) - (i*lowerWindowsYOffset));
					k++;
				}
			}
		}
		for (int k = 0; k < (columns * floors); k) {
			for (int j = 0; j < floors; j++) {
				_civilians[k] = new Civilian(civHeight, civWidth, (_body.x + civOffset + (j*(_body.width / _columns))), (_body.y - civHeight));
				k++;
			}
		}
		_color = buildingColor;
			
		_civSpawnTimer = 0.0f;
		_firstFire = true;
	}

	building::~building() {
		
	}
	
	void building::setCivBounceDirection(int i, Direction x) {
		_civilians[i]->setBounceDirection(x);
	}
	
	Rectangle building::getCivilianBody(int i) {
		return _civilians[i]->getBody();
	}

	bool building::getCivIsAlive(int i) {
		return _civilians[i]->getIsAlive();
	}

	bool building::getCivIsSaved(int i) {
		return _civilians[i]->getIsSaved();
	}

	int building::getFloors() {
		return _floors;
	}

	int building::getColumns() {
		return _columns;
	}

	void building::playFire() {
		int fireCount = 0;
		for (int i = 0; i < numberOfWindows; i++){
			if (_windows[i]->getFire) {
				fireCount++;
			}
		}
		if (fireCount>=1){
			if (!IsSoundPlaying(ambientFire)) {
				PlaySound(ambientFire);
			}
		}
	}

	void building::initFire() {
		if (_firstFire) {
			for (int i = 0; i < _columns; i++) {
				_windows[i]->catchFire();
			}
			_firstFire = false;
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
		for (int i = 0; i < _columns; i++) { //Recorre las ventanas del ultimo piso y verifica si las que estan abajo estan prendidas.
			if (_windows[i + _columns]->getOnFire() && !_windows[i]->getOnFire()) {
				_windows[i]->spreadFireTimer();
			}
		}
		for (int i = 0; i < _floors; i++){//Recorre las ventanas de la primera columna desde la derecha y verifica si las que estan a la derecha estan prendidas.
			if (_windows[(i*_columns) + 1]->getOnFire() && !_windows[i]->getOnFire()) {
				_windows[i*_columns]->spreadFireTimer();
			}
		}
		for  (int i = _columns; i < (_columns*_floors)-_floors; i++){//Recorre las ventanas entre el primer y ultimo piso y verifica si las que estan arriba o abajo estan prendidas.
			if (_windows[i - _columns]->getOnFire() && !_windows[i]->getOnFire()||
				_windows[i + _columns]->getOnFire() && !_windows[i]->getOnFire()) {
				_windows[i]->spreadFireTimer();
			}
		}
		for (int i = 1; i < (_columns*_floors) - 1; i) {//Recorre las ventanas entre la primera y ultima columna y verifica si las que estan a la izquierda o derecha estan prendidas.
			if (_windows[i - 1]->getOnFire() && !_windows[i]->getOnFire() ||
				_windows[i + 1]->getOnFire() && !_windows[i]->getOnFire()) {
				_windows[i]->spreadFireTimer();
			}
			i++;
			if (i == _columns - 1) {
				i += 2;
			}
		}
		for (int i = _columns-1; i < (_columns-1)*_floors; i+=_columns) {//Recorre las ventanas de la ultima columna desde la derecha y verifica si las que estan a la izquierda estan prendidas.
			if (_windows[i - 1]->getOnFire() && !_windows[i]->getOnFire()) {
				_windows[i]->spreadFireTimer();
			}
		}
		for (int i = (_columns*_floors) - _columns; i < (_columns*_floors); i++) { //Recorre las ventanas del primer piso y verifica si las que estan arriba estan prendidas.
			if (_windows[i - _columns]->getOnFire() && !_windows[i]->getOnFire()) {
				_windows[i]->spreadFireTimer();
			}
		}
	}

	int building::countLargeFires() {
		int largeFires = 0;
		for (int i = 0; i < _columns*_floors; i++){
			if (_windows[i]->getFire() == largeFire) {
				largeFires++;
			}
		}
		return largeFires;
	}

	void building::spawnCiv() {
		_civSpawnTimer += GetFrameTime();
		if (_civSpawnTimer >= 5.0f) {
			int random = GetRandomValue(0, (_columns*_floors) - 1);
			_civilians[random]->setOnRoof(true);
			_civSpawnTimer = 0.0f;
		}
	}

	void building::civJumpTimers() {
		for (int i = 0; i < _columns*_floors; i++){
			if (_civilians[i]->getOnRoof()){
				_civilians[i]->jumpTimer();
			}
		}
	}

	void building::civBounce(int i) {
		_civilians[i]->bounce();
	}

	void building::resetCivBounce(int i) {
		_civilians[i]->resetBounceForce();
	}

	void building::killCivilians(int i) {
		_civilians[i]->die();
	}

	void building::saveCivilians(int i) {
		_civilians[i]->saved();
	}

	void building::draw() {
		//DrawRectangleRec(_body, _color);
		for (int i = 0; i < (_floors*_columns); i++){
			_windows[i]->draw();
		}
		for (int i = 0; i < (_floors*_columns); i++) {
			_civilians[i]->draw();
		}
	}
}