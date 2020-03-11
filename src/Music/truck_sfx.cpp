#include "truck_sfx.h"


using namespace SummerLab;

namespace SummerLab {
	Sound truckSiren;
	Sound motorOn;
	Sound motorOff;
	Sound motorLoop;
	Sound waterShot;

	void loadTruckSounds() {
		truckSiren = LoadSound("res/assets/snd/truck/truckSiren.wav");
		motorOn = LoadSound("res/assets/snd/truck/motorOn.wav");
		motorOff = LoadSound("res/assets/snd/truck/motorOff.wav");
		motorLoop = LoadSound("res/assets/snd/truck/motorLoop.wav");
		waterShot = LoadSound("res/assets/snd/truck/watershot.wav");
	}
	void unloadTruckSounds() {
		UnloadSound(truckSiren);
		UnloadSound(motorOn);
		UnloadSound(motorOff);
		UnloadSound(motorLoop);
		UnloadSound(waterShot);
	}
}