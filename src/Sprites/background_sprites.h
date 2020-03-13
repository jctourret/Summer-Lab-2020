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
		killCount,
	};

	enum KillCount {
		noDead,
		oneDead,
		twoDead,
		threeDead,
	};

	enum SkiesList {
		sky1,
		sky2,
		clouds1,
		clouds2,
		sun,
		sunlights
	};

	enum Time {
		day,
		afternoon,
		night
	};



	extern Texture2D backgroundSprites[8];
	extern Texture2D skiesSprites[6];
	extern Texture2D gameOverBurnSprite[3];
	extern Texture2D gameOverDeadSprite[3];
	extern Texture2D gameOverDeadExtraSprite[3];
	extern Texture2D gameOverWinSprite[3];
	extern Texture2D killCountSprites[3];
	extern Texture2D buildingCracks[5];
	extern Texture2D buildingCollapsing[16];

	void loadBackGroundSprites();
	void unloadBackGroundSprites();
		
}

#endif