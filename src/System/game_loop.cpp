#include "game_loop.h"

#include "raylib.h"



using namespace SummerLab;

namespace SummerLab{

	game_loop::game_loop(){
		_pantalla = new pantalla();
		InitWindow(_pantalla->getAnchoPantalla(), _pantalla->getAltoPantalla(), "Summerlab");
		SetExitKey(KEY_ESCAPE);

		_estado = enMenu;
		_gameOn = true;
		
		_creditos = NULL;
		_menu = NULL;
		_gameplay = NULL;

		_creditos = new creditos();
		_menu = new menu();
		_gameplay = new gameplay();
	}

	game_loop::~game_loop() {
		if (_creditos != NULL) {

		}
		if (_menu != NULL) {
			
		}
		if (_gameplay != NULL) {

		}
	}

	void game_loop::gameLoop() {
		while (_gameOn || WindowShouldClose()) {
			
			switch (_estado) {
			case enMenu:
				_menu->run();
				if (_menu->getToGameplay()) {
					_gameState = onGameplay;
					_menu->setToGameplay(false);
				}
				if (_menu->getToCredits()) {
					_gameState = onCredits;
					_menu->setToCredits(false);
				}
				break;
			case enGameplay:
				_gameplay->run();
				if (_gameplay->getToMenu()) {
					_gameState = onMenu;
					_gameplay->setToMenu(false);
				}
				if (_gameplay->getToCredits()) {
					_gameState = onCredits;
					_gameplay->setToCredits(false);
				}
				break;
			case enCreditos:
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