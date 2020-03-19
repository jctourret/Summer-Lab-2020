#include "pause.h"

#include "System/game_states.h"
#include "Sprites/pause_sprites.h"
#include "Music/music.h"

using namespace SummerLab;

#include <iostream>
using namespace std;

namespace SummerLab {

	static bool cursorInResume;
	static bool cursorInMute;
	static bool cursorInMenu;
	static bool cursorInExit;

	static const float posXButtons = 763;
	static const float widthButtons = 411;
	static const float heightButtons = 152;

	static const float resumeY = 197;
	static const float muteY = 397;
	static const float menuY = 597;
	static const float exitY = 797;

	Pause::Pause(){
		_pauseSprite = pauseSprite;
		_resumeShineSprite = resumeShineSprite;
		_muteShineSprite = muteShineSprite;
		_menuShineSprite = menuShineSprite;
		_exitShineSprite = exitShineSprite;

		_resumeRec.x = posXButtons;
		_resumeRec.y = resumeY;
		_resumeRec.width = widthButtons;
		_resumeRec.height = heightButtons;

		_muteRec.x = posXButtons;
		_muteRec.y = muteY;
		_muteRec.width = widthButtons;
		_muteRec.height = heightButtons;

		_menuRec.x = posXButtons;
		_menuRec.y = menuY;
		_menuRec.width = widthButtons;
		_menuRec.height = heightButtons;

		_exitRec.x = posXButtons;
		_exitRec.y = exitY;
		_exitRec.width = widthButtons;
		_exitRec.height = heightButtons;

		_gamePaused = false;

		cursorInResume = false;
		cursorInMute = false;
		cursorInMenu = false;
		cursorInExit = false;
	}

	Pause::~Pause(){

	}

	void Pause::inputPause() {
		if (_gamePaused == false && IsKeyPressed(KEY_ESCAPE)) {
			_gamePaused = true;
		}
		else if (_gamePaused == true) {
			Vector2 mousePos = GetMousePosition();

			if (IsKeyPressed(KEY_ESCAPE)) {
				_gamePaused = false;
			}

			if (CheckCollisionPointRec(mousePos, _resumeRec)) {
				cursorInResume = true;
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					cursorInResume = false;
					_gamePaused = false;
				}
			}
			else if (CheckCollisionPointRec(mousePos, _muteRec)) {
				cursorInMute = true;
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					muteAllSounds();
				}
			}
			else if (CheckCollisionPointRec(mousePos, _menuRec)) {
				cursorInMenu = true;
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					gameState = onMenu;
				}
			}
			else if (CheckCollisionPointRec(mousePos, _exitRec)) {
				cursorInExit = true;
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					gameState = closeGame;
				}
			}
			else {
				cursorInResume = false;
				cursorInMute = false;
				cursorInMenu = false;
				cursorInExit = false;
			}
		}
	}

	void Pause::drawPause() {
		if (_gamePaused == true) {
			DrawTexture(_pauseSprite, 0, 0, RAYWHITE);

			if (cursorInResume == true)
				DrawTexture(_resumeShineSprite, 0, 0, RAYWHITE);
			else if (cursorInMute == true)
				DrawTexture(_muteShineSprite, 0, 0, RAYWHITE);
			else if (cursorInMenu == true)
				DrawTexture(_menuShineSprite, 0, 0, RAYWHITE);
			else if (cursorInExit == true)
				DrawTexture(_exitShineSprite, 0, 0, RAYWHITE);
		}
	}

	bool Pause::getGamePaused() {
		return _gamePaused;
	}

}