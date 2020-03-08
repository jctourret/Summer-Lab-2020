#ifndef CIVILIANS_SPRITES_H 
#define CIVILIANS_SPRITES_H 

#include "raylib.h" 

namespace SummerLab {

	extern Texture2D normalFemale[3];
	extern Texture2D normalMale[3];
	extern Texture2D partyFemale[3];
	extern Texture2D partyMale[3];
	extern Texture2D workingFemale[3];
	extern Texture2D workingMale[3];

	void loadCiviliansSprites();
	void unloadCiviliansSprites();
}

#endif