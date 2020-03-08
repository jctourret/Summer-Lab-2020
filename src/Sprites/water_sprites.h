#ifndef WATER_SPRITES_H 
#define WATER_SPRITES_H 

#include "raylib.h" 

namespace SummerLab {

	extern Texture2D waterShot1Sprite[3];
	extern Texture2D waterShot2Sprite[3];
	extern Texture2D waterShot3Sprite[3];
	extern Texture2D waterShot4Sprite[3];
	extern Texture2D waterShot5Sprite[3];
	extern Texture2D waterShot6Sprite[3];
	extern Texture2D waterShot7Sprite[3];

	void loadWaterShotSprites();
	void unloadWaterShotSprites();

}

#endif