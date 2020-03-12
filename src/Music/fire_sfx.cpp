#include "fire_sfx.h"


using namespace SummerLab;

namespace SummerLab {
	Sound initFire;
	Sound extinguishFire;
	Sound ambientFire;
	Sound buildingCollapse;

	void loadFireSounds() {
		initFire = LoadSound("res/assets/snd/fire/initFire.ogg");
		extinguishFire = LoadSound("res/assets/snd/fire/extinguishFire.ogg");
		ambientFire = LoadSound("res/assets/snd/fire/ambientFire.ogg");
		buildingCollapse = LoadSound("res/assets/snd/fire/buildingCollapse.ogg");
	}
	void unloadFireSounds() {
		UnloadSound(initFire);
		UnloadSound(extinguishFire);
		UnloadSound(ambientFire);
		UnloadSound(buildingCollapse);
	}
}