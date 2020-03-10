#include "bakcground_sprites.h"

using namespace SummerLab;

namespace SummerLab {

	static const int gameWidth = 1920;
	static const int gameHeight = 1080;

	Texture2D backgroundSprite;
	Texture2D barricadeSprite;
	Texture2D gameOverBurnSprite;
	Texture2D gameOverDeadSprite;
	Texture2D gameOverWinSprite;

	static Image backgroundImage;
	static Image barricadeImage;
	static Image gameOverBurnImage;
	static Image gameOverDeadImage;
	static Image gameOverWinImage;

	void loadBackGroundSprites() {
		backgroundImage = LoadImage("res/assets/img/background/FondoNivel1.jpg");
		barricadeImage = LoadImage("res/assets/img/background/barricade.png");
		gameOverBurnImage = LoadImage("res/assets/img/gameOver/gameOverBurn.png");
		gameOverDeadImage = LoadImage("res/assets/img/gameOver/gameOverDead.png");
		gameOverWinImage = LoadImage("res/assets/img/gameOver/gameOverWin.png");

		ImageResize(&backgroundImage, gameWidth, gameHeight);
		ImageResize(&barricadeImage, gameWidth, gameHeight);
		ImageResize(&gameOverBurnImage, gameWidth, gameHeight);
		ImageResize(&gameOverDeadImage, gameWidth, gameHeight);
		ImageResize(&gameOverWinImage, gameWidth, gameHeight);

		backgroundSprite = LoadTextureFromImage(backgroundImage);
		barricadeSprite = LoadTextureFromImage(barricadeImage);
		gameOverBurnSprite = LoadTextureFromImage(gameOverBurnImage);
		gameOverDeadSprite = LoadTextureFromImage(gameOverDeadImage);
		gameOverWinSprite = LoadTextureFromImage(gameOverWinImage);

		UnloadImage(backgroundImage);
		UnloadImage(barricadeImage);
		UnloadImage(gameOverBurnImage);
		UnloadImage(gameOverDeadImage);
		UnloadImage(gameOverWinImage);
	}

	void unloadBackGroundSprites() {
		UnloadTexture(backgroundSprite);
		UnloadTexture(barricadeSprite);
		UnloadTexture(gameOverBurnSprite);
		UnloadTexture(gameOverDeadSprite);
		UnloadTexture(gameOverWinSprite);
	}

}