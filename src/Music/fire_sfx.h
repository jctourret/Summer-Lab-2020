#ifndef FIRE_SFX_H
#define FIRE_SFX_H

#include "raylib.h"

namespace SummerLab {
	extern Sound initFire;
	extern Sound extinguishFire;
	extern Sound ambientFire;
	extern Sound buildingCollapse;

	void loadFireSounds();
	void unloadFireSounds();
}
#endif