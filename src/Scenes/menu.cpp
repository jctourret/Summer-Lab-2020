#include "menu.h"

#include "raylib.h"
#include "System/screen.h"
#include "Music/music.h"
#include "Sprites/truck_sprites.h"

using namespace SummerLab;

namespace SummerLab {
	static const float playButtonHeight = 120;
	static const float playButtonWidth = 420;
	static const float playButtonX = screenWidth - screenWidth/2 -33;
	static const float playButtonY = screenHeight/20 + 52;

	static const float creditsButtonHeight = 120;
	static const float creditsButtonWidth = 420;
	static const float creditsButtonX = screenWidth - screenWidth / 4 -48;
	static const float creditsButtonY = screenHeight / 20+50;

	static const int titlePosY = screenHeight/6;
	static const int titleFontSize = 50;
	static const int textFontSize = 20;
	static const int playPosX = screenWidth / 2;
	static const int playPosY = screenHeight - screenHeight/6;

	static const float truckHeight = 212.0f;
	static const float truckWidth = 357.0f;
	static const Color truckColor = RED;

	static const Color textColor = MAROON;

	menu::menu(){
		_menuOn = true;
		_toGameplay = false;
		_toCredits = false;
		_toGameplayTimer = 0;
		_toCreditsTimer = 0;
		_playButton.height = playButtonHeight;
		_playButton.width = playButtonWidth;
		_playButton.x = playButtonX;
		_playButton.y = playButtonY;
		_creditsButton.height = creditsButtonHeight;
		_creditsButton.width = creditsButtonWidth;
		_creditsButton.x = creditsButtonX;
		_creditsButton.y = creditsButtonY;
		Image background = LoadImage("res/assets/img/menu/background.png");
		ImageResize(&background, screenWidth, screenHeight);
		_background = LoadTextureFromImage(background);
		UnloadImage(background);
		_logo = LoadTexture("res/assets/img/menu/logo.png");
		_menuButtons = LoadTexture("res/assets/img/menu/menuButtons.png");
		_playShine = LoadTexture("res/assets/img/menu/playShine.png");
		_creditsShine = LoadTexture ("res/assets/img/menu/creditsShine.png");
		_menuTruck = new truck(truckHeight*2, truckWidth*2, screenWidth / 2, screenHeight - (screenHeight / 4) - truckHeight);
		_menuTruck->setIsOnMenu(true);
	}

	menu::~menu(){
		if (_menuTruck != NULL){
			delete _menuTruck;
		}
		UnloadTexture(_background);
		UnloadTexture(_logo);
		UnloadTexture(_playShine);
		UnloadTexture(_creditsShine);
	}

	void menu::setToGameplay(bool toGameplay){
		_toGameplay = toGameplay;
	}

	void menu::setToCredits(bool toCredits) {
		_toCredits = toCredits;
	}

	bool menu::getToGameplay() {
		return _toGameplay;
	}

	bool menu::getToCredits(){
		return _toCredits;
	}

	void menu::run() {
		_menuOn = true;
		while (_menuOn && !WindowShouldClose()) {
			update();
			draw();
		}
	}

	void menu::update() {
		if (IsKeyPressed(KEY_ENTER)) {
			_menuOn = false;
			_toGameplay = true;
		}
		_menuTruck->move();
		_menuTruck->shoot();
		_menuTruck->setWaterTank(100);
		shootButtons(_menuTruck->getWaterShot());
		playMenuTheme();
	}

	void menu::draw() {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexture(_background, 0, 0, RAYWHITE);
		DrawTexture(_logo, 0, 10, RAYWHITE);
		DrawTexture(_menuButtons,0,0, RAYWHITE);
		if(isPlayButtonShot(_menuTruck->getWaterShot()) == true){
			DrawTexture(_playShine, 0, 0, RAYWHITE);
		}
		if(isCreditsButtonShot(_menuTruck->getWaterShot()) == true){
			DrawTexture(_creditsShine,0,0,RAYWHITE);
		}
		_menuTruck->draw();
		EndDrawing();
	}

	void menu::shootButtons(Rectangle rec) {
		if (isPlayButtonShot(rec)==true){
			_toGameplayTimer += GetFrameTime();
			if (_toGameplayTimer > 3.0f) {
				_menuOn = false;
				_toGameplay = true;
				_toGameplayTimer = 0;
			}
		}
		if (isCreditsButtonShot(rec)==true) {
			_toCreditsTimer += GetFrameTime();
			if (_toCreditsTimer > 3.0f) {
				_menuOn = false;
				_toCredits = true;
				_toCreditsTimer = 0;
			}
		}
	}

	bool menu::isPlayButtonShot(Rectangle rec) {
		if (rec.x >= _playButton.x - rec.width &&
			rec.x <= _playButton.x + _playButton.width + rec.width &&
			rec.y > _playButton.y &&
			rec.y < _playButton.y + _playButton.height) {
			return true;
		}
	}

	bool menu::isCreditsButtonShot(Rectangle rec) {
		if (rec.x >= _creditsButton.x - rec.width &&
			rec.x <= _creditsButton.x + _creditsButton.width + rec.width &&
			rec.y > _creditsButton.y &&
			rec.y < _creditsButton.y + _creditsButton.height) {
			return true;
		}
	}

	void menu::playMenuTheme() {
		if (!IsSoundPlaying(menuTheme)) {
			PlaySound(menuTheme);
		}
	}
}