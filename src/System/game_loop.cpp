#include "game_loop.h"

#include "raylib.h"



using namespace SummerLab;

namespace SummerLab{

	game_loop::game_loop(){
		_screen = new screen();
		InitWindow(_screen->getScreenWidth(), _screen->getScreenHeight, "Summerlab");
		SetExitKey(KEY_ESCAPE);

		_gamestate = onMenu;
		_gameOn = true;
		
		_credits = NULL;
		_menu = NULL;
		_gameplay = NULL;

		_credits = new credits();
		_menu = new menu();
		_gameplay = new gameplay();
	}

	game_loop::~game_loop() {
		if (_credits != NULL) {
			delete _credits;
		}
		if (_menu != NULL) {
			delete _menu;
		}
		if (_gameplay != NULL) {
			delete _gameplay;
		}
	}

	void game_loop::gameLoop() {
		while (_gameOn || WindowShouldClose()) {
			
			switch (_gamestate) {
			case onMenu:
				_menu->run();
				if (_menu->getToGameplay()) {
					_gamestate = onGameplay;
					_menu->setToGameplay(false);
				}
				if (_menu->getToCredits()) {
					_gamestate = onCredits;
					_menu->setToCredits(false);
				}
				break;
			case onGameplay:
				_gameplay->run();
				if (_gameplay->getToMenu()) {
					_gamestate = onMenu;
					_gameplay->setToMenu(false);
				}
				if (_gameplay->getToCredits()) {
					_gamestate = onCredits;
					_gameplay->setToCredits(false);
				}
				break;
			case onCredits:
				_creditos->run();
				if (_credits->getToGameplay()) {
					_gameState = onGameplay;
					_credits->setToGameplay(false);
				}
				if (_credits->getToMenu()) {
					_gameState = onMenu;
					_credits->setToMenu(false);
				}
				break;
			default:
				break;
			}
		}
	}

}