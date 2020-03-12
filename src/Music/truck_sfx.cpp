#include "truck_sfx.h"


using namespace SummerLab;

namespace SummerLab {
	Sound truckSiren;
	Sound motorOn;
	Sound motorOff;
	Sound motorLoop;
	Sound waterShot;
	Sound trampolineSound[3];

	void loadTruckSounds() {
		truckSiren = LoadSound("res/assets/snd/truck/truckSiren.ogg");
		motorOn = LoadSound("res/assets/snd/truck/motorOn.ogg");
		motorOff = LoadSound("res/assets/snd/truck/motorOff.ogg");
		motorLoop = LoadSound("res/assets/snd/truck/motorLoop.ogg");
		waterShot = LoadSound("res/assets/snd/truck/waterShot.ogg");
		trampolineSound[0] = LoadSound("res/assets/snd/trampoline/trampoline0.ogg");
		trampolineSound[1] = LoadSound("res/assets/snd/trampoline/trampoline1.ogg");
		trampolineSound[2] = LoadSound("res/assets/snd/trampoline/trampoline2.ogg");
		trampolineSound[3] = LoadSound("res/assets/snd/trampoline/trampoline3.ogg");

	}
	void unloadTruckSounds() {
		UnloadSound(truckSiren);
		UnloadSound(motorOn);
		UnloadSound(motorOff);
		UnloadSound(motorLoop);
		UnloadSound(waterShot);
	}
}