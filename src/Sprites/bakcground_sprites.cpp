#include "bakcground_sprites.h"

using namespace SummerLab;

namespace SummerLab {

	Texture2D backgroundSprites[6];
	Texture2D skiesSprites[6];
	Texture2D gameOverBurnSprite;
	Texture2D gameOverDeadSprite;
	Texture2D gameOverWinSprite;

	void loadBackGroundSprites() {
		backgroundSprites[buildingP] = LoadTexture("res/assets/img/background/building.png");
		backgroundSprites[barricade] = LoadTexture("res/assets/img/background/barricade.png");
		backgroundSprites[buldingsBG] = LoadTexture("res/assets/img/background/buildingsBG.png");
		backgroundSprites[crowd] = LoadTexture("res/assets/img/background/crowd.png");
		backgroundSprites[hydrant] = LoadTexture("res/assets/img/background/hydrant.png");
		backgroundSprites[street] = LoadTexture("res/assets/img/background/street.png");

		skiesSprites[day] = LoadTexture("res/assets/img/background/skyday.png");
		skiesSprites[afternoon] = LoadTexture("res/assets/img/background/skyafternoon.png");
		skiesSprites[night] = LoadTexture("res/assets/img/background/skynight.png");
		skiesSprites[clouds] = LoadTexture("res/assets/img/background/clouds.png");
		skiesSprites[sun] = LoadTexture("res/assets/img/background/sun.png");
		skiesSprites[sunlights] = LoadTexture("res/assets/img/background/sunlights.png");

		gameOverBurnSprite = LoadTexture("res/assets/img/gameOver/gameOverBurn.png");
		gameOverDeadSprite = LoadTexture("res/assets/img/gameOver/gameOverDead.png");
		gameOverWinSprite = LoadTexture("res/assets/img/gameOver/gameOverWin.png");
	}

	void unloadBackGroundSprites() {
		for (int i = 0; i < 6; i++) {
			UnloadTexture(backgroundSprites[i]);
		}
		for (int i = 0; i < 6; i++) {
			UnloadTexture(skiesSprites[i]);
		}

		UnloadTexture(gameOverBurnSprite);
		UnloadTexture(gameOverDeadSprite);
		UnloadTexture(gameOverWinSprite);
	}

}