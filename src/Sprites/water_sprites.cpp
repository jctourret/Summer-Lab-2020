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

	void loadWaterShotSprites() {
		waterShot1Sprite[0] = LoadTexture("res/assets/img/water/watershot1a.png");
		waterShot1Sprite[1] = LoadTexture("res/assets/img/water/watershot1b.png");
		waterShot1Sprite[2] = LoadTexture("res/assets/img/water/watershot1c.png");

		waterShot2Sprite[0] = LoadTexture("res/assets/img/water/watershot2a.png");
		waterShot2Sprite[1] = LoadTexture("res/assets/img/water/watershot2b.png");
		waterShot2Sprite[2] = LoadTexture("res/assets/img/water/watershot2c.png");

		waterShot3Sprite[0] = LoadTexture("res/assets/img/water/watershot3a.png");
		waterShot3Sprite[1] = LoadTexture("res/assets/img/water/watershot3b.png");
		waterShot3Sprite[2] = LoadTexture("res/assets/img/water/watershot3c.png");

		waterShot4Sprite[0] = LoadTexture("res/assets/img/water/watershot4a.png");
		waterShot4Sprite[1] = LoadTexture("res/assets/img/water/watershot4b.png");
		waterShot4Sprite[2] = LoadTexture("res/assets/img/water/watershot4c.png");

		waterShot5Sprite[0] = LoadTexture("res/assets/img/water/watershot5a.png");
		waterShot5Sprite[1] = LoadTexture("res/assets/img/water/watershot5b.png");
		waterShot5Sprite[2] = LoadTexture("res/assets/img/water/watershot5c.png");

		waterShot6Sprite[0] = LoadTexture("res/assets/img/water/watershot6a.png");
		waterShot6Sprite[1] = LoadTexture("res/assets/img/water/watershot6b.png");
		waterShot6Sprite[2] = LoadTexture("res/assets/img/water/watershot6c.png");

		waterShot7Sprite[0] = LoadTexture("res/assets/img/water/watershot7a.png");
		waterShot7Sprite[1] = LoadTexture("res/assets/img/water/watershot7b.png");
		waterShot7Sprite[2] = LoadTexture("res/assets/img/water/watershot7c.png");
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