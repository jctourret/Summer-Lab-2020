#include "background_sprites.h"

using namespace SummerLab;

namespace SummerLab {

	Texture2D backgroundSprites[8];
	Texture2D skiesSprites[6];
	Texture2D gameOverBurnSprite[3];
	Texture2D gameOverDeadSprite[3];
	Texture2D gameOverDeadExtraSprite[3];
	Texture2D gameOverWinSprite[3];

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
		skiesSprites[sky2] = LoadTexture("res/assets/img/background/skies2.png");
		skiesSprites[clouds1] = LoadTexture("res/assets/img/background/clouds1.png");
		skiesSprites[clouds2] = LoadTexture("res/assets/img/background/clouds2.png");
		skiesSprites[sun] = LoadTexture("res/assets/img/background/sun.png");
		skiesSprites[sunlights] = LoadTexture("res/assets/img/background/sunlights.png");

		gameOverBurnSprite[day] = LoadTexture("res/assets/img/gameOver/GameOverBurnDay.png");
		gameOverBurnSprite[afternoon] = LoadTexture("res/assets/img/gameOver/GameOverBurnAfternoon.png");
		gameOverBurnSprite[night] = LoadTexture("res/assets/img/gameOver/GameOverBurnNight.png");

		gameOverDeadSprite[day] = LoadTexture("res/assets/img/gameOver/GameOverDeadDay.png");
		gameOverDeadSprite[afternoon] = LoadTexture("res/assets/img/gameOver/GameOverDeadAfternoon.png");
		gameOverDeadSprite[night] = LoadTexture("res/assets/img/gameOver/GameOverDeadNight.png");

		gameOverDeadSprite[day] = LoadTexture("res/assets/img/gameOver/GameOverDeadExtraDay.png");
		gameOverDeadSprite[afternoon] = LoadTexture("res/assets/img/gameOver/GameOverDeadExtraAfternoon.png");
		gameOverDeadSprite[night] = LoadTexture("res/assets/img/gameOver/GameOverDeadExtraNight.png");

		gameOverWinSprite[day] = LoadTexture("res/assets/img/gameOver/gameOverWinDay.png");
		gameOverWinSprite[afternoon] = LoadTexture("res/assets/img/gameOver/gameOverWinAfternoon.png");
		gameOverWinSprite[night] = LoadTexture("res/assets/img/gameOver/gameOverWinNight.png");
	}

	void unloadBackGroundSprites() {
		for (int i = 0; i < 8; i++) {
			UnloadTexture(backgroundSprites[i]);
		}
		for (int i = 0; i < 6; i++) {
			UnloadTexture(skiesSprites[i]);
		}

		for (int i = 0; i < 3; i++) {
			UnloadTexture(gameOverBurnSprite[i]);
			UnloadTexture(gameOverDeadSprite[i]);
			UnloadTexture(gameOverDeadExtraSprite[i]);
			UnloadTexture(gameOverWinSprite[i]);
		}

	}

}