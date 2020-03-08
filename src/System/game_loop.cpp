#include "game_loop.h"

#include "raylib.h"

#include "Sprites/sprites_general.h"

using namespace SummerLab;

namespace SummerLab{

	game_loop::game_loop(){
		_screen = NULL;
		_screen = new screen();
		InitWindow(_screen->getScreenWidth(), _screen->getScreenHeight(), "Summerlab");
		SetExitKey(KEY_ESCAPE);
		//ToggleFullscreen();
		loadAllSprites();

		_gamestate = onMenu;
		_gameOn = true;
		
		_menu = NULL;
		_gameplay = NULL;

		_menu = new menu();
		_gameplay = new gameplay();
	}

	game_loop::~game_loop() {
		if (_menu != NULL) {
			delete _menu;
		}
		if (_gameplay != NULL) {
			delete _gameplay;
		}
		if (_screen != NULL) {
			delete _screen;
		}
		unloadAllSprites();
	}

	void game_loop::gameLoop() {
		while (_gameOn && !WindowShouldClose()) {
			switch (_gamestate) {
			case onMenu:
				_menu->run();
				if (_menu->getToGameplay()) {
					_gamestate = onGameplay;
					_menu->setToGameplay(false);
				}
				break;
			case onGameplay:
				_gameplay->run();
				if (_gameplay->getToMenu()) {
					_gamestate = onMenu;
					_gameplay->setToMenu(false);
				}
				break;
			default:
				break;
			}
		}
	}

}