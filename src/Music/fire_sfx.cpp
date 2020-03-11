#include "fire_sfx.h"


using namespace SummerLab;

namespace SummerLab {
	Sound initFire;
	Sound extinguishFire;
	Sound ambientFire;
	Sound buildingCollapse;

	void loadFireSounds() {
		initFire = LoadSound("res/assets/snd/fire/initFire.wav");
		extinguishFire = LoadSound("res/assets/snd/fire/extinguishFire.wav");
		ambientFire = LoadSound("res/assets/snd/fire/ambientFire.wav");
		buildingCollapse = LoadSound("res/assets/snd/fire/buildingCollapse.wav");
	}
	void unloadFireSounds() {
		UnloadSound(initFire);
		UnloadSound(extinguishFire);
		UnloadSound(ambientFire);
		UnloadSound(buildingCollapse);
	}
}