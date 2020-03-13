#ifndef TRUCK_SPRITES_H 
#define TRUCK_SPRITES_H 

#include "raylib.h" 

namespace SummerLab {

	extern Texture2D truckSprite[5];
	extern Texture2D sirenSprite;
	extern Texture2D menuTruckSprite[5];
	extern Texture2D menuSirenSprite;

	void loadTruckSprites();
	void unloadTruckSprites();
}

#endif