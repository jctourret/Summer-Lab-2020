#ifndef PAUSE_H
#define PAUSE_H

#include "raylib.h"

namespace SummerLab {

	class Pause{
		Texture2D _pauseSprite;
		Texture2D _resumeShineSprite;
		Texture2D _muteShineSprite;
		Texture2D _menuShineSprite;
		Texture2D _exitShineSprite;
		Rectangle _resumeRec;
		Rectangle _muteRec;
		Rectangle _menuRec;
		Rectangle _exitRec;
		bool _gamePaused;
	public:
		Pause();
		~Pause();
		void inputPause();
		void drawPause();
		bool getGamePaused();
	};

}

#endif