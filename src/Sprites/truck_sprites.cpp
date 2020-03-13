#include "truck_sprites.h" 

using namespace SummerLab;

namespace SummerLab {

	static const int maxSprites = 5;

	static const float truckHeight = 212.0f;
	static const float truckWidth = 357.0f;

	static const float menuTruckHeight = 212.0f * 2;
	static const float menuTruckWidth = 357.0f * 2;

	Texture2D truckSprite[5];
	Texture2D sirenSprite;

	Texture2D menuTruckSprite[5];
	Texture2D menuSirenSprite;

	static Image truckImage[5];
	static Image sirenImage;

	static Image menuTruckImage[5];
	static Image menuSirenImage;

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

		menuTruckImage[0] = LoadImage("res/assets/img/truck/Camion00.png");
		menuTruckImage[1] = LoadImage("res/assets/img/truck/Camion25.png");
		menuTruckImage[2] = LoadImage("res/assets/img/truck/Camion50.png");
		menuTruckImage[3] = LoadImage("res/assets/img/truck/Camion75.png");
		menuTruckImage[4] = LoadImage("res/assets/img/truck/Camion100.png");
		menuSirenImage = LoadImage("res/assets/img/truck/LightSiren.png");

		for (int i = 0; i < maxSprites; i++) {
			ImageResize(&menuTruckImage[i], menuTruckWidth, menuTruckHeight);
		}

		ImageResize(&sirenImage, truckWidth, truckHeight);
		ImageResize(&menuSirenImage, menuTruckWidth, menuTruckHeight);

		for (int i = 0; i < maxSprites; i++) {
			truckSprite[i] = LoadTextureFromImage(truckImage[i]);
			menuTruckSprite[i] = LoadTextureFromImage(menuTruckImage[i]);
		}

		sirenSprite = LoadTextureFromImage(sirenImage);

		for (int i = 0; i < maxSprites; i++) {
			UnloadImage(truckImage[i]);
			UnloadImage(menuTruckImage[i]);
		}

		UnloadImage(sirenImage);
		UnloadImage(menuSirenImage);
	}

	void unloadTruckSprites() {
		for (int i = 0; i < maxSprites; i++) {
			UnloadTexture(truckSprite[i]);
		}

		UnloadTexture(sirenSprite);
	}

}
