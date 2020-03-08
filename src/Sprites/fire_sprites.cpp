#include "fire_sprites.h" 

using namespace SummerLab;

namespace SummerLab {

	static const int maxSprites = 3;

	Texture2D smallFireSprite[maxSprites];
	Texture2D mediumFireSprite[maxSprites];
	Texture2D largeFireSprite[maxSprites];

	static const int largeFireWidth = 109;
	static const int largeFireHeight = 133;
	static Image largeFireImage[maxSprites];

	void loadFireSprites() {
		smallFireSprite[0] = LoadTexture("res/assets/img/fire/smallFire1.png");
		smallFireSprite[1] = LoadTexture("res/assets/img/fire/smallFire2.png");
		smallFireSprite[2] = LoadTexture("res/assets/img/fire/smallFire3.png");

		mediumFireSprite[0] = LoadTexture("res/assets/img/fire/mediumFire1.png");
		mediumFireSprite[1] = LoadTexture("res/assets/img/fire/mediumFire2.png");
		mediumFireSprite[2] = LoadTexture("res/assets/img/fire/mediumFire3.png");

		largeFireImage[0] = LoadImage("res/assets/img/fire/largeFire1.png");
		largeFireImage[1] = LoadImage("res/assets/img/fire/largeFire2.png");
		largeFireImage[2] = LoadImage("res/assets/img/fire/largeFire3.png");

		for (int i = 0; i < maxSprites; i++) {
			ImageResize(&largeFireImage[i], largeFireWidth, largeFireHeight);
		}

		for (int i = 0; i < maxSprites; i++) {
			largeFireSprite[i] = LoadTextureFromImage(largeFireImage[i]);
		}

		for (int i = 0; i < maxSprites; i++) {
			UnloadImage(largeFireImage[i]);
		}

	}

	void unloadFireSprites() {
		for (int i = 0; i < maxSprites; i++) {
			UnloadTexture(smallFireSprite[i]);
			UnloadTexture(mediumFireSprite[i]);
			UnloadTexture(largeFireSprite[i]);
		}
	}

}