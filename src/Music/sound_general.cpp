#include "sound_general.h"

#include "raylib.h"

using namespace SummerLab;

namespace SummerLab {

	void loadAllSounds() {
		loadTruckSounds();
		loadFireSounds();
		loadScreams();
		loadThemes();
	}

	void unloadAllSounds() {
		unloadTruckSounds();
		unloadFireSounds();
		unloadScreams();
		unloadThemes();
	}

}