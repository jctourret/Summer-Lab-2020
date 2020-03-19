#include "game_loop.h"

#include "raylib.h"

#include "System/game_states.h"
#include "Sprites/sprites_general.h"
#include "Music/sound_general.h"
using namespace SummerLab;

namespace SummerLab{

	static bool gameMuted = false;

	game_loop::game_loop() {
		_screen = NULL;
		_screen = new screen();
		InitWindow(_screen->getScreenWidth(), _screen->getScreenHeight(), "Summerlab");
		SetExitKey(KEY_VOLUME_DOWN);
		ToggleFullscreen();
		InitAudioDevice();
		loadAllSprites();
		loadAllSounds();
		SetMasterVolume(0.02f);
		gameState = onMenu;
		
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
		CloseWindow();
	}

	void game_loop::gameLoop() {
		while (gameState != closeGame && !WindowShouldClose()) {
			switch (gameState) {
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
					_hoseGame = _menu->getHoseGame();
					_keyboardGame = _menu->getKeyboardGame();
				}
				break;
			case onGameplay:
				if (_gameplay == NULL) {
					_gameplay = new gameplay(_keyboardGame, _hoseGame);
				}
				else if (_gameplay != NULL) {
					_gameplay->run();
				}
				break;
			case onCredits:
				if (_credits == NULL) {
					_credits = new credits();
				}
				else if (_credits != NULL) {
					_credits->run();
				}
			default:
				break;
			}
		}
	}

}