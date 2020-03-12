#ifndef BACKGROUND_SPRITES_H
#define BACKGROUND_SPRITES_H

#include "raylib.h"

namespace SummerLab {

	enum BackgroundList {
		buildingP,
		barricade,
		buldingsBGDay,
		buildingsBGAfternoon,
		buildingsBGNight,
		crowd,
		hydrant,
		street,
	};

	enum SkiesList {
		sky1,
		clouds1,
		clouds2,
		sun,
		sunlights
	};

	extern Texture2D backgroundSprites[8];
	extern Texture2D skiesSprites[5];
	extern Texture2D gameOverBurnSprite;
	extern Texture2D gameOverDeadSprite;
	extern Texture2D gameOverWinSprite;

	void loadBackGroundSprites();
	void unloadBackGroundSprites();
		
}

#endif