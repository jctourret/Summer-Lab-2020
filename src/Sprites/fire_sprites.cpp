#include "fire_sprites.h" 

using namespace SummerLab;

namespace SummerLab {

	static const int maxSprites = 3;

	Texture2D smallFireSprite[3];
	Texture2D mediumFireSprite[3];
	Texture2D largeFireSprite[3];

	void loadFireSprites() {
		smallFireSprite[0] = LoadTexture("res/assets/img/fire/smallFire1.png");
		smallFireSprite[1] = LoadTexture("res/assets/img/fire/smallFire2.png");
		smallFireSprite[2] = LoadTexture("res/assets/img/fire/smallFire3.png");

		mediumFireSprite[0] = LoadTexture("res/assets/img/fire/mediumFire1.png");
		mediumFireSprite[1] = LoadTexture("res/assets/img/fire/mediumFire2.png");
		mediumFireSprite[2] = LoadTexture("res/assets/img/fire/mediumFire3.png");

		largeFireSprite[0] = LoadTexture("res/assets/img/fire/largeFire1.png");
		largeFireSprite[1] = LoadTexture("res/assets/img/fire/largeFire2.png");
		largeFireSprite[2] = LoadTexture("res/assets/img/fire/largeFire3.png");
	}

	void unloadFireSprites() {
		for (int i = 0; i < maxSprites; i++) {
			UnloadTexture(smallFireSprite[i]);
			UnloadTexture(mediumFireSprite[i]);
			UnloadTexture(largeFireSprite[i]);
		}
	}

}