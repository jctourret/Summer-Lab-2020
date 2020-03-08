#ifndef FIRE_SPRITES_H 
#define FIRE_SPRITES_H 

#include "raylib.h" 

namespace SummerLab {

	extern Texture2D smallFireSprite[3];
	extern Texture2D mediumFireSprite[3];
	extern Texture2D largeFireSprite[3];

	void loadFireSprites();
	void unloadFireSprites();

}

#endif