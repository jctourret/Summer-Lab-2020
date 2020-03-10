#include "truck_sprites.h" 

using namespace SummerLab;

namespace SummerLab {

	static const int maxSprites = 5;

	static const float truckHeight = 212.0f;
	static const float truckWidth = 357.0f;

	Texture2D truckSprite[5];
	Texture2D sirenSprite;

	static Image truckImage[5];
	static Image sirenImage;

	void loadTruckSprites() {
		truckImage[0] = LoadImage("res/assets/img/truck/Camion00.png");
		truckImage[1] = LoadImage("res/assets/img/truck/Camion25.png");
		truckImage[2] = LoadImage("res/assets/img/truck/Camion50.png");
		truckImage[3] = LoadImage("res/assets/img/truck/Camion75.png");
		truckImage[4] = LoadImage("res/assets/img/truck/Camion100.png");
		sirenImage = LoadImage("res/assets/img/truck/LightSiren.png");

		for (int i = 0; i < maxSprites; i++) {
			ImageResize(&truckImage[i], truckWidth, truckHeight);
		}

		ImageResize(&sirenImage, truckWidth, truckHeight);

		for (int i = 0; i < maxSprites; i++) {
			truckSprite[i] = LoadTextureFromImage(truckImage[i]);
		}

		sirenSprite = LoadTextureFromImage(sirenImage);

		for (int i = 0; i < maxSprites; i++) {
			UnloadImage(truckImage[i]);
		}

		UnloadImage(sirenImage);
	}

	void unloadTruckSprites() {
		for (int i = 0; i < maxSprites; i++) {
			UnloadTexture(truckSprite[i]);
		}

		UnloadTexture(sirenSprite);
	}

}
