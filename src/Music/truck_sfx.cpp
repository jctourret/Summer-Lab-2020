#include "truck_sfx.h"


using namespace SummerLab;

namespace SummerLab {
	Sound truckSiren;
	Sound motorOn;
	Sound motorOff;
	Sound motorLoop;
	Sound waterShot;
	Sound truckSiren;

	void loadTruckSounds() {
		truckSiren = LoadSound("res/assets/snd/s/helpMale");
		motorOn = LoadSound("res/assets/snd/music/helpFemale");
		motorOff = LoadSound("res/assets/snd/music/helpFemale");
		motorLoop = LoadSound("res/assets/snd/music/helpFemale");
		waterShot = LoadSound("res/assets/snd/music/helpFemale");
		truckSiren = LoadSound("res/assets/snd/music/helpFemale");
	}
	void unloadTruckSounds() {
		UnloadSound(truckSiren);
		UnloadSound(motorOn);
		UnloadSound(motorOff);
		UnloadSound(motorLoop);
		UnloadSound(waterShot);
		UnloadSound(truckSiren);
	}
}