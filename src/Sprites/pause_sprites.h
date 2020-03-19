#ifndef PAUSE_SPRITES_H
#define PAUSE_SPRITES_H

#include "raylib.h"

namespace SummerLab {
	extern Texture2D pauseSprite;
	extern Texture2D resumeShineSprite;
	extern Texture2D muteShineSprite;
	extern Texture2D menuShineSprite;
	extern Texture2D exitShineSprite;

	void loadPauseSprites();
	void unloadPauseSprites();
}

#endif