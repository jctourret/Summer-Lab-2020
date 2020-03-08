#include "ambulance_sprites.h" 

using namespace SummerLab;

namespace SummerLab {

	static const float ambulanceHeight = 175;
	static const float ambulanceWidth = 342;

	Texture2D ambulanceRightSprite;
	Texture2D ambulanceLeftSprite;

	static Image ambulanceRightImage;
	static Image ambulanceLeftImage;

	void loadAmbulanceSprites() {
		ambulanceRightImage = LoadImage("res/assets/img/ambulance/ambulanceRight.png");
		ambulanceLeftImage = LoadImage("res/assets/img/ambulance/ambulanceLeft.png");

		ImageResize(&ambulanceRightImage, ambulanceWidth, ambulanceHeight);
		ImageResize(&ambulanceLeftImage, ambulanceWidth, ambulanceHeight);

		ambulanceRightSprite = LoadTextureFromImage(ambulanceRightImage);
		ambulanceLeftSprite = LoadTextureFromImage(ambulanceLeftImage);

		UnloadImage(ambulanceRightImage);
		UnloadImage(ambulanceLeftImage);
	}

	void unloadAmbulanceSprites() {
		UnloadTexture(ambulanceRightSprite);
		UnloadTexture(ambulanceLeftSprite);
	}

}