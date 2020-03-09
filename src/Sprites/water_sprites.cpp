#include "water_sprites.h" 

using namespace SummerLab;

namespace SummerLab {

	static const int maxSprites = 3;

	Texture2D waterShot1Sprite[3];
	Texture2D waterShot2Sprite[3];
	Texture2D waterShot3Sprite[3];
	Texture2D waterShot4Sprite[3];
	Texture2D waterShot5Sprite[3];
	Texture2D waterShot6Sprite[3];
	Texture2D waterShot7Sprite[3];

	static Image waterShot1Image[3];
	static Image waterShot2Image[3];
	static Image waterShot3Image[3];
	static Image waterShot4Image[3];
	static Image waterShot5Image[3];
	static Image waterShot6Image[3];
	static Image waterShot7Image[3];

	static const int waterShotWidth1 = 142;
	static const int waterShotWidth2 = 253;
	static const int waterShot1Height = 145;
	static const int waterShot2Height = 273;
	static const int waterShot3Height = 348;
	static const int waterShot4Height = 409;
	static const int waterShot5Height = 476;
	static const int waterShot6Height = 546;
	static const int waterShot7Height = 637;

	void loadWaterShotSprites() {
		waterShot1Image[0] = LoadImage("res/assets/img/water/watershot1a.png");
		waterShot1Image[1] = LoadImage("res/assets/img/water/watershot1b.png");
		waterShot1Image[2] = LoadImage("res/assets/img/water/watershot1c.png");

		waterShot2Image[0] = LoadImage("res/assets/img/water/watershot2a.png");
		waterShot2Image[1] = LoadImage("res/assets/img/water/watershot2b.png");
		waterShot2Image[2] = LoadImage("res/assets/img/water/watershot2c.png");

		waterShot3Image[0] = LoadImage("res/assets/img/water/watershot3a.png");
		waterShot3Image[1] = LoadImage("res/assets/img/water/watershot3b.png");
		waterShot3Image[2] = LoadImage("res/assets/img/water/watershot3c.png");

		waterShot4Image[0] = LoadImage("res/assets/img/water/watershot4a.png");
		waterShot4Image[1] = LoadImage("res/assets/img/water/watershot4b.png");
		waterShot4Image[2] = LoadImage("res/assets/img/water/watershot4c.png");

		waterShot5Image[0] = LoadImage("res/assets/img/water/watershot5a.png");
		waterShot5Image[1] = LoadImage("res/assets/img/water/watershot5b.png");
		waterShot5Image[2] = LoadImage("res/assets/img/water/watershot5c.png");

		waterShot6Image[0] = LoadImage("res/assets/img/water/watershot6a.png");
		waterShot6Image[1] = LoadImage("res/assets/img/water/watershot6b.png");
		waterShot6Image[2] = LoadImage("res/assets/img/water/watershot6c.png");

		waterShot7Image[0] = LoadImage("res/assets/img/water/watershot7a.png");
		waterShot7Image[1] = LoadImage("res/assets/img/water/watershot7b.png");
		waterShot7Image[2] = LoadImage("res/assets/img/water/watershot7c.png");

		for (int i = 0; i < maxSprites; i++) {
			ImageResize(&waterShot1Image[i], waterShotWidth1, waterShot1Height);
			ImageResize(&waterShot2Image[i], waterShotWidth2, waterShot2Height);
			ImageResize(&waterShot3Image[i], waterShotWidth2, waterShot3Height);
			ImageResize(&waterShot4Image[i], waterShotWidth2, waterShot4Height);
			ImageResize(&waterShot5Image[i], waterShotWidth2, waterShot5Height);
			ImageResize(&waterShot6Image[i], waterShotWidth2, waterShot6Height);
			ImageResize(&waterShot7Image[i], waterShotWidth2, waterShot7Height);
		}

		for (int i = 0; i < maxSprites; i++) {
			waterShot1Sprite[i] = LoadTextureFromImage(waterShot1Image[i]);
			waterShot2Sprite[i] = LoadTextureFromImage(waterShot2Image[i]);
			waterShot3Sprite[i] = LoadTextureFromImage(waterShot3Image[i]);
			waterShot4Sprite[i] = LoadTextureFromImage(waterShot4Image[i]);
			waterShot5Sprite[i] = LoadTextureFromImage(waterShot5Image[i]);
			waterShot6Sprite[i] = LoadTextureFromImage(waterShot6Image[i]);
			waterShot7Sprite[i] = LoadTextureFromImage(waterShot7Image[i]);
		}

		for (int i = 0; i < maxSprites; i++) {
			UnloadImage(waterShot1Image[i]);
			UnloadImage(waterShot2Image[i]);
			UnloadImage(waterShot3Image[i]);
			UnloadImage(waterShot4Image[i]);
			UnloadImage(waterShot5Image[i]);
			UnloadImage(waterShot6Image[i]);
			UnloadImage(waterShot7Image[i]);
		}

	}

	void unloadWaterShotSprites() {
		for (int i = 0; i < maxSprites; i++) {
			UnloadTexture(waterShot1Sprite[i]);
			UnloadTexture(waterShot2Sprite[i]);
			UnloadTexture(waterShot3Sprite[i]);
			UnloadTexture(waterShot4Sprite[i]);
			UnloadTexture(waterShot5Sprite[i]);
			UnloadTexture(waterShot6Sprite[i]);
			UnloadTexture(waterShot7Sprite[i]);
		}
	}

}