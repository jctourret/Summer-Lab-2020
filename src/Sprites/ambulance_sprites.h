#ifndef AMBULANCE_SPRITES_H 
#define AMBULANCE_SPRITES_H 

#include "raylib.h" 

namespace SummerLab {

	extern Texture2D ambulanceRightSprite;
	extern Texture2D ambulanceLeftSprite;

	void loadAmbulanceSprites();
	void unloadAmbulanceSprites();

}

#endif