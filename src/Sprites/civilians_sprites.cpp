#include "civilians_sprites.h" 

using namespace SummerLab;

namespace SummerLab {

	static const int maxSprites = 3;

	static const float civOffset = 85;
	static const float civHeight = 106;
	static const float civWidth = 91;

	Texture2D normalFemale[maxSprites];
	Texture2D normalMale[maxSprites];
	Texture2D partyFemale[maxSprites];
	Texture2D partyMale[maxSprites];
	Texture2D workingFemale[maxSprites];
	Texture2D workingMale[maxSprites];

	static Image normalFemaleImage[maxSprites];
	static Image normalMaleImage[maxSprites];
	static Image partyFemaleImage[maxSprites];
	static Image partyMaleImage[maxSprites];
	static Image workingFemaleImage[maxSprites];
	static Image workingMaleImage[maxSprites];

	void loadCiviliansSprites() {
		normalFemaleImage[0] = LoadImage("res/assets/img/civilians/normalFemale1.png");
		normalFemaleImage[1] = LoadImage("res/assets/img/civilians/normalFemale2.png");
		normalFemaleImage[2] = LoadImage("res/assets/img/civilians/normalFemale3.png");

		normalMaleImage[0] = LoadImage("res/assets/img/civilians/normalMale1.png");
		normalMaleImage[1] = LoadImage("res/assets/img/civilians/normalMale2.png");
		normalMaleImage[2] = LoadImage("res/assets/img/civilians/normalMale3.png");

		partyFemaleImage[0] = LoadImage("res/assets/img/civilians/partyFemale1.png");
		partyFemaleImage[1] = LoadImage("res/assets/img/civilians/partyFemale2.png");
		partyFemaleImage[2] = LoadImage("res/assets/img/civilians/partyFemale3.png");

		partyMaleImage[0] = LoadImage("res/assets/img/civilians/partyMale1.png");
		partyMaleImage[1] = LoadImage("res/assets/img/civilians/partyMale2.png");
		partyMaleImage[2] = LoadImage("res/assets/img/civilians/partyMale3.png");

		workingFemaleImage[0] = LoadImage("res/assets/img/civilians/workingFemale1.png");
		workingFemaleImage[1] = LoadImage("res/assets/img/civilians/workingFemale2.png");
		workingFemaleImage[2] = LoadImage("res/assets/img/civilians/workingFemale3.png");

		workingMaleImage[0] = LoadImage("res/assets/img/civilians/workingMale1.png");
		workingMaleImage[1] = LoadImage("res/assets/img/civilians/workingMale2.png");
		workingMaleImage[2] = LoadImage("res/assets/img/civilians/workingMale3.png");

		for (int i = 0; i < maxSprites; i++) {
			ImageResize(&normalFemaleImage[i], civWidth, civHeight);
			ImageResize(&normalMaleImage[i], civWidth, civHeight);
			ImageResize(&partyFemaleImage[i], civWidth, civHeight);
			ImageResize(&partyMaleImage[i], civWidth, civHeight);
			ImageResize(&workingFemaleImage[i], civWidth, civHeight);
			ImageResize(&workingMaleImage[i], civWidth, civHeight);
		}

		for (int i = 0; i < maxSprites; i++) {
			normalFemale[i] = LoadTextureFromImage(normalFemaleImage[i]);
			normalMale[i] = LoadTextureFromImage(normalFemaleImage[i]);
			partyFemale[i] = LoadTextureFromImage(normalFemaleImage[i]);
			partyMale[i] = LoadTextureFromImage(normalFemaleImage[i]);
			workingFemale[i] = LoadTextureFromImage(normalFemaleImage[i]);
			workingMale[i] = LoadTextureFromImage(normalFemaleImage[i]);
		}

		for (int i = 0; i < maxSprites; i++) {
			UnloadImage(normalFemaleImage[i]);
			UnloadImage(normalMaleImage[i]);
			UnloadImage(partyFemaleImage[i]);
			UnloadImage(partyMaleImage[i]);
			UnloadImage(workingFemaleImage[i]);
			UnloadImage(workingMaleImage[i]);
		}

	}

	void unloadCiviliansSprites() {
		for (int i = 0; i < maxSprites; i++) {
			UnloadTexture(normalFemale[i]);
			UnloadTexture(normalMale[i]);
			UnloadTexture(partyFemale[i]);
			UnloadTexture(partyMale[i]);
			UnloadTexture(workingFemale[i]);
			UnloadTexture(workingMale[i]);
		}
	}

}