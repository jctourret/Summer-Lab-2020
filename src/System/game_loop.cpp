#include "game_loop.h"

#include "raylib.h"

#include "Sprites/sprites_general.h"
#include "Music/sound_general.h"

using namespace SummerLab;

namespace SummerLab{

	game_loop::game_loop(){
		_screen = NULL;
		_screen = new screen();
		InitWindow(_screen->getScreenWidth(), _screen->getScreenHeight(), "Summerlab");
		SetExitKey(KEY_ESCAPE);
		//ToggleFullscreen();
		InitAudioDevice();
		loadAllSprites();
		loadAllSounds();

		_gamestate = onMenu;
		_gameOn = true;
		
		_menu = NULL;
		_gameplay = NULL;
		_credits = NULL;

		_menu = new menu();
		//_gameplay = new gameplay();
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
		unloadAllSounds();
	}

	void game_loop::gameLoop() {
		while (_gameOn && !WindowShouldClose()) {
			switch (_gamestate) {
			case onMenu:
				if (_gameplay != NULL) {
					delete _gameplay;
					_gameplay = NULL;
				}
				if (_credits != NULL) {
					delete _credits;
					_credits = NULL;
				}
				if (_menu != NULL) {
					_menu->run();
					if (_menu->getToGameplay()) {
						_gamestate = onGameplay;
						_menu->setToGameplay(false);
					}
					if (_menu->getToCredits()) {
						_gamestate = onCredits;
						_menu->setToCredits(false);
					}
				}
				break;
			case onGameplay:
				if (_gameplay == NULL) {
					_gameplay = new gameplay();
				}
				else if (_gameplay != NULL) {
					_gameplay->run();
					if (_gameplay->getToMenu()) {
						_gamestate = onMenu;
						_gameplay->setToMenu(false);
					}
				}
				break;
			case onCredits:
				if (_credits == NULL) {
					_credits = new credits();
				}
				else if (_credits != NULL) {
					_credits->run();
					if (_credits->getToMenu()) {
						_gamestate = onMenu;
						_credits->setToMenu(false);
					}
				}
			default:
				break;
			}
		}
	}

}