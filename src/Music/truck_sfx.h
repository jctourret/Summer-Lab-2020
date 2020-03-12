#ifndef TRUCK_SFX_H
#define TRUCK_SFX_H

#include "raylib.h"

namespace SummerLab {
	extern Sound truckSiren;
	extern Sound motorOn;
	extern Sound motorOff;
	extern Sound motorLoop;
	extern Sound waterShot;
	extern Sound trampolineSound[3];

	void loadTruckSounds();
	void unloadTruckSounds();
}
#endif