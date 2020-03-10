#ifndef BACKGROUND_SPRITES_H
#define BACKGROUND_SPRITES_H

#include "raylib.h"

namespace SummerLab {

	enum BackgroundList {
		buildingP,
		barricade,
		buldingsBG,
		crowd,
		hydrant,
		street,
	};

	enum SkiesList {
		day,
		afternoon,
		night,
		clouds,
		sun,
		sunlights
	};

	extern Texture2D backgroundSprites[6];
	extern Texture2D skiesSprites[6];
	extern Texture2D gameOverBurnSprite;
	extern Texture2D gameOverDeadSprite;
	extern Texture2D gameOverWinSprite;

	void loadBackGroundSprites();
	void unloadBackGroundSprites();
		
}

#endif