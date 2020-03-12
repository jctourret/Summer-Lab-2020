#include "background_sprites.h"

using namespace SummerLab;

namespace SummerLab {

	Texture2D backgroundSprites[8];
	Texture2D skiesSprites[5];
	Texture2D gameOverBurnSprite;
	Texture2D gameOverDeadSprite;
	Texture2D gameOverWinSprite;

	void loadBackGroundSprites() {
		backgroundSprites[buildingP] = LoadTexture("res/assets/img/background/building.png");
		backgroundSprites[barricade] = LoadTexture("res/assets/img/background/barricade.png");
		backgroundSprites[buldingsBGDay] = LoadTexture("res/assets/img/background/buildingsBGDay.png");
		backgroundSprites[buildingsBGAfternoon] = LoadTexture("res/assets/img/background/buildingsBGAfternoon.png");
		backgroundSprites[buildingsBGNight] = LoadTexture("res/assets/img/background/buildingsBGNight.png");
		backgroundSprites[crowd] = LoadTexture("res/assets/img/background/crowd.png");
		backgroundSprites[hydrant] = LoadTexture("res/assets/img/background/hydrant.png");
		backgroundSprites[street] = LoadTexture("res/assets/img/background/street.png");

		skiesSprites[sky1] = LoadTexture("res/assets/img/background/skies1.png");
		skiesSprites[clouds1] = LoadTexture("res/assets/img/background/clouds1.png");
		skiesSprites[clouds2] = LoadTexture("res/assets/img/background/clouds2.png");
		skiesSprites[sun] = LoadTexture("res/assets/img/background/sun.png");
		skiesSprites[sunlights] = LoadTexture("res/assets/img/background/sunlights.png");

		gameOverBurnSprite = LoadTexture("res/assets/img/gameOver/gameOverBurn.png");
		gameOverDeadSprite = LoadTexture("res/assets/img/gameOver/gameOverDead.png");
		gameOverWinSprite = LoadTexture("res/assets/img/gameOver/gameOverWin.png");
	}

	void unloadBackGroundSprites() {
		for (int i = 0; i < 8; i++) {
			UnloadTexture(backgroundSprites[i]);
		}
		for (int i = 0; i < 5; i++) {
			UnloadTexture(skiesSprites[i]);
		}

		UnloadTexture(gameOverBurnSprite);
		UnloadTexture(gameOverDeadSprite);
		UnloadTexture(gameOverWinSprite);
	}

}