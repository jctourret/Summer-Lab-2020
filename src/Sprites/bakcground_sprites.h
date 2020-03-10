#ifndef BACKGROUND_SPRITES_H
#define BACKGROUND_SPRITES_H

#include "raylib.h"

namespace SummerLab {

	extern Texture2D backgroundSprite;
	extern Texture2D barricadeSprite;
	extern Texture2D gameOverBurnSprite;
	extern Texture2D gameOverDeadSprite;
	extern Texture2D gameOverWinSprite;

	void loadBackGroundSprites();
	void unloadBackGroundSprites();
		
}

#endif